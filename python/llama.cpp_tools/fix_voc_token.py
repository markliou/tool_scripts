from pathlib import Path
from transformers import AutoTokenizer

pad_no = 61952 - 61875 # 這邊放上vocalbulary和token的數量差異
tokenizer_model_name = 'Breeze-7B-Instruct-v0.1' # 這邊放上要轉換的模型
model_path = 'output'
new_tokens = [f"<pad{i}>" for i in range(pad_no)]

tokenizer = AutoTokenizer.from_pretrained(tokenizer_model_name, trust_remote_code=True)
tokenizer.pad_token = tokenizer.eos_token
tokenizer.padding_side = "right"

tokenizer.add_tokens(new_tokens)

tokenizer.save_pretrained(Path(model_path))
tokenizer.save_vocabulary(model_path)
