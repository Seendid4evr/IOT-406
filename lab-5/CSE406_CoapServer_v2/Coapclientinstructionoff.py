import asyncio
import aiocoap
from aiocoap.numbers import media_types_rev

async def main():
    ctx = await aiocoap.Context.create_client_context()

    req = aiocoap.Message(
        code=aiocoap.PUT,
        uri="coap://192.168.0.108/light",
        payload=b'1'                        # <- send "1" instead of "0"
    )
    # (optional) declare content-format to match your ESP response type
    req.opt.content_format = media_types_rev['application/octet-stream']

    try:
        res = await ctx.request(req).response
    except Exception as e:
        print("Failed to send PUT request:", e)
    else:
        print("Response Code:", res.code)
        print("Response Payload:", res.payload.decode('utf-8'))

if __name__ == "__main__":
    asyncio.run(main())
