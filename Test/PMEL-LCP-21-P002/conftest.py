def pytest_addoption(parser):
    parser.addoption("--port", action="store", default="COM1")