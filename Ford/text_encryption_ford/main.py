from typing import Union

from fastapi import FastAPI

app = FastAPI()


@app.get("/cipher")
def convert_plaintext(input):
    return input