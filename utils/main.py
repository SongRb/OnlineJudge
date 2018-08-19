from downloader import Downloader
from readme import generate


def main():
    Downloader().download()
    generate()


if __name__ == "__main__":
    main()
