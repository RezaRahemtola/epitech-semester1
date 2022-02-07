import actions

def get_action_for_args(args, index) -> actions.Action:
    for action in [actions.TRANSLATE, actions.SCALE, actions.ROTATE, actions.REFLECT]:
        if args[index] == f"-{action.flag}":
            return action
    print(f"Error: Cannot find action for flag {args[index]}")
    exit(84)

def get_n_args(args, nb, index):
    return [float(args[i]) for i in range(index, index + nb)]