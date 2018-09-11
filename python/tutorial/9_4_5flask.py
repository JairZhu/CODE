from flask import Flask, render_template, request
app = Flask(__name__)
@app.route('/')
def home():
    thing = request.values.get('thing')
    height = request.values.get('height')
    color = request.values.get('color')
    return render_template('home.html', thing=thing, height=height, color=color)
app.run(port=9999, debug=True)