import heapq
from collections import defaultdict, Counter

class Node:
    def __init__(self, char, freq):
        self.char = char
        self.freq = freq
        self.left = None
        self.right = None

    def __lt__(self, other):
        return self.freq < other.freq

def build_huffman_tree(text):
    frequency = Counter(text)
    heap = [Node(char, freq) for char, freq in frequency.items()]
    heapq.heapify(heap)

    while len(heap) > 1:
        left_child = heapq.heappop(heap)
        right_child = heapq.heappop(heap)

        internal_node = Node(None, left_child.freq + right_child.freq)
        internal_node.left = left_child
        internal_node.right = right_child

        heapq.heappush(heap, internal_node)

    return heap[0]

def build_huffman_codes(node, current_code="", codes=None):
    if codes is None:
        codes = {}
    if node is not None:
        if node.char is not None:
            codes[node.char] = current_code
        build_huffman_codes(node.left, current_code + "0", codes)
        build_huffman_codes(node.right, current_code + "1", codes)
    return codes

def encode(text, codes):
    encoded_text = ''.join(codes[char] for char in text)
    return encoded_text

def decode(encoded_text, root):
    decoded_text = ""
    current_node = root

    for bit in encoded_text:
        if bit == '0':
            current_node = current_node.left
        else:
            current_node = current_node.right

        if current_node.char is not None:
            decoded_text += current_node.char
            current_node = root

    return decoded_text

text = "happy new year"
huffman_tree = build_huffman_tree(text)
huffman_codes = build_huffman_codes(huffman_tree)
encoded_text = encode(text, huffman_codes)
decoded_text = decode(encoded_text, huffman_tree)

for char, code in huffman_codes.items():
    print(f"Character: {char}, Huffman Code: {code}")

print("Original Text:", text)
print("Encoded Text:", encoded_text)
print("Decoded Text:", decoded_text)