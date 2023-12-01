with open('../data/1.txt') as file:
    lines = file.readlines()
    total = 0
    str_to_int = {'one': 1, 'two': 2, 'three': 3, 'four': 4, 'five': 5,
                    'six': 6, 'seven': 7, 'eight': 8, 'nine': 9, '1':1,
                  '2':2, '3':3, '4':4, '5':5, '6':6, '7':7,
                  '8':8, '9':9, '0':0}
    for line in lines:
        indices = {line.index(char): str_to_int[char] for i, char in enumerate(['one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0']) if char in line}
        indices.update({line.rindex(char): str_to_int[char] for i, char in enumerate(['one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0']) if char in line})

        print(line, indices)
        if len(indices) == 0:
            number = 0
        elif len(indices) == 1:
            i = list(indices.keys())[0]
            number = int(str(indices[i]) + str(indices[i]))
        else:
            number = int(str(indices[min(indices.keys())]) + str(indices[max(indices.keys())]))

        print(number)
        total += number

    print(total)