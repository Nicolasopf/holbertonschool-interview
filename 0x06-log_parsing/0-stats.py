#!/usr/bin/python3
''' Computes file size and status codes metrics from a logs file. '''
from sys import stdin
import re
from signal import signal, SIGINT


def signal_handler(sig, frame):
    ''' Handle ctrl c signal, what do to when ctrl + c pressed. '''
    pass


def print_output(file_size_total, codes_count, status_codes):
    ''' Prints the file size and codes count. 'Does not print codes 0 value '''
    print("File size: {}".format(file_size_total))
    for code in status_codes:
        if codes_count[code] > 0:
            print("{}: {}".format(code, codes_count[code]))


signal(SIGINT, signal_handler)
line_counter = 0  # Each 10, have to print.
file_size_total = 0
status_codes = [200, 301, 400, 401, 403,
                404, 405, 500]  # Possible status codes

codes_count = {}  # Where to save the codes match
for code in status_codes:
    codes_count[code] = 0


for line in stdin:
    # Check if the format matches:
    full_match = re.fullmatch(
        r"(\d{1,3}.){3}\d{1,3} - \[\d{4}-\d{2}-\d{2} \d{2}:\d{2}:\d{2}.\d*\]"
        " \"GET /projects/260 HTTP/1.1\" \d{3} \d{1,4}\n", line)
    # In case of match, full_match will return an object, if not found, None.

    if full_match:
        line_counter += 1
        tokens = line.split()
        code = int(tokens[-2])
        file_size = int(tokens[-1])

        if code in status_codes:
            codes_count[code] += 1
        file_size_total += file_size

        if line_counter == 10:
            print_output(file_size_total, codes_count, status_codes)
            line_counter = 0

if line_counter != 10:
    print_output(file_size_total, codes_count, status_codes)
