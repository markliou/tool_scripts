from huggingface_hub import snapshot_download
model_id="lmsys/vicuna-13b-v1.5"
download_loc = "vicuna-hf"
snapshot_download(repo_id=model_id, local_dir=download_loc,
                  local_dir_use_symlinks=False, revision="main")