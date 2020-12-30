import axios from "axios";

export default class Teste {
  led = async (status) => {
    console.log("teste");
    try {
      const resposta = await axios({
        url: `http://192.168.15.31/?${status}`,
        method: "GET",
      });
      return resposta;
    } catch (e) {
      return e;
    }
  };
}
