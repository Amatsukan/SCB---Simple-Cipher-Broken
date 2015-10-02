from enigma import PermutationUtils
from enigma import Key
from enigma import Enigma

import string

def ci(cipher):
	permut = PermutationUtils()
	ringstellung = ["A", "A", "A"]
	plugboard = permut.build_permutation('')

	rotors = {1:'I', 2:'II', 3:'III', 4:'IV', 5:'V'}
	notches = {1:'Q', 2:'E', 3:'V', 4:'J', 5:'Z'}
	correct_rotor = []

	enigma = Enigma()
	cont = 0
	possible_keys = []

	for i in range(5):
		for j in range(5):
			for k in range(5):
				if i != j and i != k and j != k:
					correct_rotor = [rotors[i+1], rotors[j+1], rotors[k+1]]
					for l1 in range(26):
						for l2 in range(26):
							for l3 in range(26):
								try_rotor_start_pos = [chr((l1+65)), chr((l2+65)), chr((l3+65))]
								k = Key(correct_rotor, ringstellung, plugboard, try_rotor_start_pos)
								plain_text = enigma.enigma_enc(cipher, k)
								frequencies = count_letters(plain_text)
								
								ic = 0.0
								for freq in frequencies.values():
									ic += (freq*(freq-1))
								ic /= ((len(plain_text))*(len(plain_text)-1))
								if ic > 0.05:
									possible_keys.append(k)

								print(correct_rotor, try_rotor_start_pos, ic)
								possibilities = []

	print possible_keys

def count_letters(text):
	total_count = 0
	letters = string.ascii_uppercase
	alphabet = {letter : 0 for letter in letters}

	for char in text:
		if char in letters:
			alphabet[char] += 1
			total_count += 1

	return alphabet		


ci('CWSNVWKRKXHDPIJGEZWKCZSFVDKXOQMYGLGKCIILAYXUTORKOOWYSRTGTUHOZMYHMSXUISHJJWSWSYIPRJQYCNVCGUMUKHWQBAAYFQHHYJCDRRJYHXYTKMLONKRBVURBWEDZXZTXOSSDKTFPFKVBIERFXCPDGXFRDUKPHOODGGTBATCYHGIAEKKRYWPAQSNQVNKZGZSDFYXGXGBLWLOIYJFIJNZKWOWOSIQFXOQHAUBYGOZNKMKQJDINNZYPWBVBOYYUWFAFRYXKGJPYTKMRWAJEKHSVGWCAAYPWHYHKGXHDGSDGZKNVRJOUJGYTOHUOVLAYEBSJODRPGHLDPUYPXQEEMMVMLDUOZIZRNSNNUKQAHOPXEEBBMAMFMCFBXIDDPXVKKE')
