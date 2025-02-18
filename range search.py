class Node:
    def __init__(self, point, left=None, right=None, axis=None):
        self.point = point
        self.left = left
        self.right = right
        self.axis = axis

def build_kd_tree(points, depth=0):
    if not points:
        return None

    axis = depth % 2  # Alternating between x-axis and y-axis
    points.sort(key=lambda x: x[axis])
    median = len(points) // 2

    return Node(
        point=points[median],
        left=build_kd_tree(points[:median], depth + 1),
        right=build_kd_tree(points[median + 1:], depth + 1),
        axis=axis
    )

def query_kd_tree(node, x_range, y_range, depth=0):
    if not node:
        return []

    axis = depth % 2

    if x_range[0] <= node.point[0] <= x_range[1] and y_range[0] <= node.point[1] <= y_range[1]:
        result = [node.point]
    else:
        result = []
    if axis == 0:
        if x_range[0] <= node.point[axis]:
            result += query_kd_tree(node.left, x_range, y_range, depth + 1)

        if x_range[1] >= node.point[axis]:
            result += query_kd_tree(node.right, x_range, y_range, depth + 1)
    else:
        
        if y_range[0] <= node.point[axis]:
            result += query_kd_tree(node.left, x_range, y_range, depth + 1)

        if y_range[1] >= node.point[axis]:
            result += query_kd_tree(node.right, x_range, y_range, depth + 1)
            
    return result

def main():
    points = [(-2, 4), (-2, 2), (-1, 4), (-1, -2), (0, 0), (1, 1), (2, 4), (2, -1), (3, 2), (3, -2)]
    kd_tree = build_kd_tree(points)

    while True:
        try:
            x_start = float(input("Enter the start of x range: "))
            x_end = float(input("Enter the end of x range: "))
            y_start = float(input("Enter the start of y range: "))
            y_end = float(input("Enter the end of y range: "))

            x_range = [x_start, x_end]
            y_range = [y_start, y_end]

            result = query_kd_tree(kd_tree, x_range, y_range)

            print("Points within the range:", result)
        except ValueError:
            print("Invalid input. Please enter numeric values.")

        repeat = input("Do you want to query again? (yes/no): ")
        if repeat.lower() != 'yes':
            break

if __name__ == "__main__":
    main()