async function loadDashboard() {
  try {
    // Fetch the JSON file created by C++
    const response = await fetch("data.json");
    const data = await response.json();

    const tableBody = document.getElementById("table-body");
    let totalInc = 0;
    let totalExp = 0;

    data.forEach((item) => {
      // Update Totals
      if (item.type === "Income") totalInc += item.amount;
      else totalExp += item.amount;

      // Create Table Row
      const row = `
                <tr>
                    <td>${item.date}</td>
                    <td><span style="color: ${item.type === "Income" ? "green" : "red"}">${item.type}</span></td>
                    <td>${item.category}</td>
                    <td>Rs. ${item.amount.toLocaleString()}</td>
                </tr>
            `;
      tableBody.innerHTML += row;
    });

    // Update Summary Cards
    document.getElementById("total-income").innerText =
      `Rs. ${totalInc.toLocaleString()}`;
    document.getElementById("total-expense").innerText =
      `Rs. ${totalExp.toLocaleString()}`;
    document.getElementById("net-balance").innerText =
      `Rs. ${(totalInc - totalExp).toLocaleString()}`;
  } catch (error) {
    console.error(
      "Error loading data. Make sure BudgetApp.exe has run successfully!",
      error,
    );
  }
}

loadDashboard();
