from downloader import Downloader
from readme import generate
from input import Input


def main():
    input = Input()
    input.get_credentials()
    Downloader(input).download()
    generate(input)


if __name__ == "__main__":
    main()
