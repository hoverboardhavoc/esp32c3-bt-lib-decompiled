/*
 * Last changed at upstream commit ed99228396aaa18935b575d600bc19da38dc4746
 * https://github.com/espressif/esp32c3-bt-lib/commit/ed99228396aaa18935b575d600bc19da38dc4746
 * Upstream date: 2025-01-03 16:50:09 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(fd62b31)
 * Source: libbtdm_app -> llm_hci.o -> hci_le_wr_rf_path_comp_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_wr_rf_path_comp_cmd_handler(short *param_1)

{
  short sVar1;
  int iVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined1 uVar5;
  
  puVar3 = (undefined1 *)
           (**(code **)(_r_modules_funcs_p + 200))
                     (0x1101,0,0x204d,1,*(code **)(_r_modules_funcs_p + 200));
  iVar4 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
  iVar2 = _p_llm_env;
  if (*(char *)(iVar4 + 0x18) == '\0') {
    uVar5 = 0xc;
  }
  else {
    if (((ushort)(param_1[1] + 0x500U) < 0xa01) &&
       (sVar1 = *param_1, (ushort)(sVar1 + 0x500U) < 0xa01)) {
      *(short *)(_p_llm_env + 200) = param_1[1];
      *(short *)(iVar2 + 0xca) = sVar1;
      *puVar3 = 0;
      goto _L62;
    }
    uVar5 = 0x12;
  }
  *puVar3 = uVar5;
_L62:
  (**(code **)(_r_ip_funcs_p + 0x8c))(puVar3,*(code **)(_r_ip_funcs_p + 0x8c));
  return 0;
}

