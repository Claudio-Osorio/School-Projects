import sqlite3
from concurrent.futures import ThreadPoolExecutor

# Returns a tuple with the amount of times that the input/string x is stored in the database
def FindMention(x):
    try:
        con = sqlite3.connect('BossMessages.db')
        cur = con.cursor()
        sql_select_query = """select count(*) from MESSAGES where Message like ? """
        cur.execute(sql_select_query, ("%" + x + "%",))
        return cur.fetchone()
    except:
        print('Failed to connect to BossMessages Database')
    finally:
        con.close()


if __name__ == "__main__":
    A = 'Coffee'
    B = 'Chocolate'
    countA = 0
    countB = 0

    # Continuous loop that retrieves the total count of mentions for words A,B
    # When the count changes with respect to the previous value (amount of mentions),
    # a message saying the new amount of occurrences pops up in the terminal.
    while True:
        with ThreadPoolExecutor(max_workers=2) as executor:
            futureObjectA = executor.submit(FindMention, A)
            futureObjectB = executor.submit(FindMention, B)

        if countA != futureObjectA.result()[0]:
            countA = futureObjectA.result()[0]
            print("Now there are " + str(countA) + " messages about " + A)

        if countB != futureObjectB.result()[0]:
            countB = futureObjectB.result()[0]
            print("Now there are " + str(countB) + " messages about " + B)
