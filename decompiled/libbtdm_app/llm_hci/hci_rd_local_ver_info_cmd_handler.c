/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llm_hci.o -> hci_rd_local_ver_info_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_rd_local_ver_info_cmd_handler(undefined4 param_1)

{
  undefined2 uVar1;
  int iVar2;
  undefined2 *puVar3;
  code *pcVar4;
  
  puVar3 = (undefined2 *)
           (**(code **)(_r_modules_funcs_p + 200))
                     (0x1101,0,param_1,10,*(code **)(_r_modules_funcs_p + 200));
  uVar1 = _sdk_cfg_priv_opts;
  *puVar3 = 0x900;
  iVar2 = _r_ip_funcs_p;
  puVar3[4] = 0x16;
  puVar3[1] = 0x16;
  *(undefined1 *)(puVar3 + 2) = 9;
  pcVar4 = *(code **)(iVar2 + 0x8c);
  puVar3[3] = uVar1;
  (*pcVar4)(pcVar4);
  return 0;
}

