from sys import exit

def check_args_nbr(argc: int, argv: list):
    if argc == 2 and argv[1] == "-h":
        print("USAGE\n\t./103cipher message key flag")
        print("DESCRIPTION\n\tmessage a message, made of ASCII characters")
        print("\tkey the encryption key, made of ASCII characters")
        print("\tflag 0 for the message to be encrypted, 1 to be decrypted")
        exit(0)
    elif argc != 4:
        print("Invalid number of arguments.")
        exit(84)

def check_message_and_key(message: str, key: str):
    if len(message) == 0:
        print("Invalid message.")
        exit(84)
    elif len(key) == 0:
        print("Invalid key.")
        exit(84)

def check_flag(flag: str):
    if flag != "0" and flag != "1":
        print("Invalid flag, retry with 0 or 1.")
        exit(84)

def check_errors(argv: list):
    argc = len(argv)
    check_args_nbr(argc, argv)
    check_message_and_key(argv[1], argv[2])
    check_flag(argv[3])
