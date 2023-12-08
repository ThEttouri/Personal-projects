from cs50 import SQL
import csv

db = SQL("sqlite:///roster1.db")

with open("students.csv") as file:
    reader = csv.DictReader(file)
    houses = []
    students = []
    assignments = []
    for line in reader:
        house = {}
        assignment = {}
        house['house'] = line['house']
        house['head'] = line['head']
        student = line['student_name']
        student_id = line['id']
        if house not in houses:
            houses.append(house)
        if student not in students:
            students.append(student)
        assignment['student_id'] = student_id
        for ID in range(len(houses)):
            if line['house'] == houses[ID]['house']:
                assignment['house_id'] = str(ID + 1)
                assignments.append(assignment)


houses_rows = db.execute("SELECT * FROM houses")
if len(houses_rows) == 0:
    for id in range(len(houses)):
        db.execute("INSERT INTO houses (house, head) VALUES (?, ?)", houses[id]['house'], houses[id]['head'])

students_rows = db.execute("SELECT * FROM students")
if len(students_rows) == 0:
    for id in range(len(students)):
        db.execute("INSERT INTO students (student_name) VALUES (?)", students[id])

assignments_rows = db.execute("SELECT * FROM assignments")
if len(assignments_rows) == 0:
    for id in range(len(assignments)):
        db.execute("INSERT INTO assignments (student_id, house_id) VALUES (?, ?)", assignments[id]['student_id'], assignments[id]['house_id'])