import json

def load_config():
    with open("config.json") as f:
        return json.load(f)

def greet(user):
    print(f"Hello, {user}! Welcome to Git practice.")

def main():
    config = load_config()
    greet(config["user"])

if __name__ == "__main__":
    main()