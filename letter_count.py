import urllib2
import string
import re

def fetch_html(page):
	response = urllib2.urlopen(page)
	return response.read()

def find_p(html):
	text = ''
	results = re.compile(r'<p>(.*?)</p>').findall(html)
	print results
	for result in results:
		text += result
	return text

def remove_tag(text):
	return re.sub('<.*?>', '', text)

def remove_nbsp(text):
	return re.sub('&nbsp;', '', text)

def count_letters(text):
	total_count = 0
	letters = string.ascii_lowercase
	alphabet = {letter : 0 for letter in letters}

	for char in text:
		if char in letters:
			alphabet[char] += 1
			total_count += 1

	for key in alphabet:
		alphabet[key] = float((alphabet[key]*100))/total_count

	return alphabet

def count_bigrams(text):
	total_count = 0
	letters = string.ascii_lowercase
	bigrams = {}

	for i in range(len(text)):
		bigram = ''
		if text[i] in letters and i < len(text)-1 and text[i+1] in letters:
			bigram = text[i] + text[i+1]
			if bigram not in bigrams:
				bigrams.update({bigram : 0})
			else:
				bigrams[bigram] += 1
			total_count += 1
	
	for key in bigrams:
		bigrams[key] = float((bigrams[key]*100))/total_count

	return bigrams

def do_the_thing(page):
	html = fetch_html(page)
	html = find_p(html)
	html = remove_tag(html)
	html = remove_nbsp(html)
	html = string.lower(html)

	result = count_letters(html)
	sorted_result = sorted(result, key=result.__getitem__, reverse=True)
	for letter in sorted_result:
		print '%s - %.2f%%' % (letter, result[letter])

	print '################'

	result_bigrams = count_bigrams(html)
	sorted_result = sorted(result_bigrams, key=result_bigrams.__getitem__, reverse=True)
	for letter in sorted_result:
		print '%s - %.2f%%' % (letter, result_bigrams[letter])

do_the_thing('https://pt.wikipedia.org/wiki/Filosofia')