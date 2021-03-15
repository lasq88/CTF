const time       = document.getElementById('time');
const parsedTime = moment(time.innerHTML);

const countdown = () => {
    const now = moment(new Date());
    const timeDifference = moment.duration(parsedTime.diff(now));

    let finalDate = moment.utc(parsedTime).format('dddd [the] Do [of] MMMM');

    let totalHours = Math.floor(timeDifference.asHours());
    totalHours += moment.utc(timeDifference.asMilliseconds()).format(':mm:ss');

    time.innerHTML = `${finalDate}. In approximately ${totalHours}.`;
}

if (parsedTime.isValid()) {
    countdown();
    setInterval(countdown, 1000);
}
// ocd