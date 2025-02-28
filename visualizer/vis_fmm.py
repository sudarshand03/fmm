import matplotlib.pyplot as plt
import pandas as pd
import numpy as np
import os

# Load FMM tree structure
def plot_fmm_tree():
    try:
        df_tree = pd.read_csv("../build/fmm_tree.csv")  # Load CSV file with tree structure
    except FileNotFoundError:
        print("Error: fmm_tree.csv not found. Run the simulation first.")
        return
    
    plt.figure(figsize=(8, 8))
    plt.scatter(df_tree["x"], df_tree["y"], s=df_tree["size"] * 100, edgecolors='black', facecolors='none')
    plt.xlabel("X")
    plt.ylabel("Y")
    plt.title("FMM Tree Structure")
    plt.show()

# Load and plot potential field
def plot_fmm_potential():
    try:
        df_potential = pd.read_csv("../build/fmm_potential.csv")  # Load CSV file with potential values
    except FileNotFoundError:
        print("Error: fmm_potential.csv not found. Run the simulation first.")
        return
    
    plt.figure(figsize=(8, 8))
    scatter = plt.scatter(df_potential["x"], df_potential["y"], c=df_potential["potential"], cmap="coolwarm", edgecolors='black')
    plt.colorbar(scatter, label="Potential")
    plt.xlabel("X")
    plt.ylabel("Y")
    plt.title("FMM Computed Potential Field")
    plt.show()

# Run both visualizations
plot_fmm_tree()
plot_fmm_potential()
