#/usr/bin/env python3
#encoding:utf-8

import os
import sys
import sqlite3

db_filename = 'test.db'
schema_filename = 'test.sql'

db_is_new = not os.path.exists(db_filename)

with sqlite3.connect(db_filename) as conn:
    if db_is_new:
        print("Creating schema")
        with open(schema_filename, 'rt') as f:
            schema = f.read()
        conn.executescript(schema)

        print("Inserting inital data")
        conn.executescript("""
        insert into project(name, description, deadline)
        values('pymotw', 'Python Module of the week', '2010-11-01');

        insert into task(details, status, deadline, project)
        values('write about select', 'done', '2010-10-03', 'pymotw');
        
        insert into task(details, status, deadline, project)
        values('write about random', 'waiting', '2010-10-10', 'pymotw');
        """)
    else:
        print('Datebase exists, assume schema does, too.')

with sqlite3.connect(db_filename) as conn:
    cursor = conn.cursor()

    #collect data
    cursor.execute("""
select id, priority, details, status, deadline from task
where project = 'pymotw'
    """)

    #fetch data
    # fetchone()
    # fetchmany(5)
    for row in cursor.fetchall():
        task_id, priority, details, status, deadline = row
        print('%2d  {%d}  %-20s [%-8s]  (%s) ' %\
                (task_id, priority, details, status, deadline))


#query metadata
with sqlite3.connect(db_filename) as conn:
    cursor = conn.cursor()

    cursor.execute("""
    select * from task where project = 'pymotw'
    """)

    print('Task table has columns: ')
    for colinfo in cursor.description:
        print(colinfo)

#positional parameters
project_name = sys.argv[1]

with sqlite3.connect(db_filename) as conn:
    cursor = conn.cursor()

    query = """  
    select id, priority, details, status, deadline from task
    where project = ?
    """

    cursor.execute(query, (project_name, ))

    for row in cursor.fetchall():
        task_id, priority, details, status, deadline  =  row
        print('%2d  {%d}  %-20s [%-8s]  (%s) ' %\
                (task_id, priority, details, status, deadline))

#named parameter
with sqlite3.connect(db_filename) as conn:
    cursor = conn.cursor()

    query = """
    select id, priority, details, status, deadline from task
    where project = :project_name
    order by deadline, priority
    """

    cursor.execute(query, {'project_name':project_name})

    for row in cursor.fetchall():
        task_id, priority, details, status, deadline = row
        print('%2d  {%d}  %-20s [%-8s]  (%s) ' %\
                (task_id, priority, details, status, deadline))
