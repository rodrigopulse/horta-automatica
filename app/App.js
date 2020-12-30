import { StatusBar } from "expo-status-bar";
import React, { useState } from "react";
import { StyleSheet, Button, View } from "react-native";
import axios from "axios";

export default function App() {
  const [led, setLed] = useState(false);
  const toggleLed = () => {
    if (led) {
      axios.get("http://192.168.15.31/?ledoff").then((res) => {
        const resposta = res.data;
        console.log("resposta: ", resposta.teste);
      });
    } else {
      axios.get("http://192.168.15.31/?ledon");
    }
    setLed(!led);
  };
  return (
    <View style={styles.container}>
      <Button
        style={styles.button}
        title={led ? "Off" : "On"}
        onPress={() => toggleLed()}
      />
      <StatusBar style="auto" />
    </View>
  );
}

const styles = StyleSheet.create({
  button: {
    width: "100%",
  },
  container: {
    width: "100%",
    flex: 1,
    backgroundColor: "#fff",
    alignItems: "center",
    justifyContent: "center",
  },
});
