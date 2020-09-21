var carPooling = function (trips, capacity) {
  // as per requirement there will be max 1000 trips
  let stops = new Array(1001);

  // let's fill each stop as 0
  stops.fill(0);

  // fill each stop with number of passengers we have in the car remaining
  for (let i = 0; i < trips.length; i++) {
    const [num_passengers, start_location, end_location] = trips[i];
    //when we start a trip we load passengers in the car
    stops[start_location] += num_passengers;
    // when we arrive, we remove passengers from the car
    stops[end_location] -= num_passengers;
  }

  // compare all passengers in every stop to the capacity
  // can alse use reduce to calculate
  // total sum of passenger in all stops
  for (let i = 0; capacity >= 0 && i < 1001; i++) {
    capacity -= stops[i];
  }

  // if we still have extra capacity left, we met the requirements
  return capacity >= 0;
};

//Fastest
/**
 * @param {number[][]} trips
 * @param {number} capacity
 * @return {boolean}
 */
var carPooling = function (trips, capacity) {
  const hash = {};

  trips.forEach(([people, start, end]) => {
    hash[start] = (hash[start] || 0) + people;
    hash[end] = (hash[end] || 0) - people;
  });

  for (let v of Object.values(hash)) {
    if (v) {
      capacity -= v;
    }

    if (capacity < 0) return false;
  }

  return true;
};
