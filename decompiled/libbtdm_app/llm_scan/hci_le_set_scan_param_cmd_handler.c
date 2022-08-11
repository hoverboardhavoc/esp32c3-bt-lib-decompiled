/*
 * Last changed at upstream commit 3b0038690a644498d6d80f1de8df0efff8cd8cf5
 * https://github.com/espressif/esp32c3-bt-lib/commit/3b0038690a644498d6d80f1de8df0efff8cd8cf5
 * Upstream date: 2022-08-11 21:28:16 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(f2e5d813)
 * Source: libbtdm_app -> llm_scan.o -> hci_le_set_scan_param_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_set_scan_param_cmd_handler(byte *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  byte *pbVar3;
  int *piVar4;
  byte bStack_21;
  
  if (*(char *)(_p_llm_env + 0xd7) == '\x02') {
_L55:
    iVar1 = 0xc;
  }
  else {
    *(undefined1 *)(_p_llm_env + 0xd7) = 1;
    bStack_21 = 0;
    while( true ) {
      iVar1 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
      if ((uint)*(byte *)(iVar1 + 0xd) <= (uint)bStack_21) break;
      if ((byte)(*(char *)(*(int *)(_p_llm_env + 8) + (uint)bStack_21 * 0x44 + 0x40) - 6U) < 3)
      break;
      bStack_21 = bStack_21 + 1;
    }
    iVar1 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
    if ((uint)bStack_21 < (uint)*(byte *)(iVar1 + 0xd)) {
      if (*(char *)((uint)bStack_21 * 0x44 + *(int *)(_p_llm_env + 8) + 0x40) != '\x06') goto _L55;
    }
    else {
      iVar1 = (**(code **)(_r_ip_funcs_p + 0x4ac))(&bStack_21,*(code **)(_r_ip_funcs_p + 0x4ac));
      if (iVar1 != 0) goto _L64;
      *(undefined1 *)(*(int *)(_p_llm_env + 8) + (uint)bStack_21 * 0x44 + 0x40) = 6;
    }
    iVar1 = 0x12;
    if (((((*(ushort *)(param_1 + 4) <= *(ushort *)(param_1 + 2)) && (*param_1 < 2)) &&
         ((ushort)(*(ushort *)(param_1 + 4) - 4) < 0x3ffd)) &&
        (((ushort)(*(ushort *)(param_1 + 2) - 4) < 0x3ffd && (param_1[6] < 4)))) &&
       ((param_1[7] < 4 && ((*(char *)(_p_llm_env + 0xc6) != '\0' || (param_1[7] < 2)))))) {
      piVar4 = (int *)(*(int *)(_p_llm_env + 8) + (uint)bStack_21 * 0x44);
      if (*piVar4 == 0) {
        iVar1 = (**(code **)(_r_modules_funcs_p + 200))
                          (0,0,0,0x10,*(code **)(_r_modules_funcs_p + 200));
        *piVar4 = iVar1;
      }
      iVar1 = 0;
      puVar2 = (undefined4 *)(*(int *)(_p_llm_env + 8) + (uint)bStack_21 * 0x44);
      pbVar3 = (byte *)*puVar2;
      pbVar3[2] = 1;
      pbVar3[4] = *param_1;
      *(undefined2 *)(pbVar3 + 6) = *(undefined2 *)(param_1 + 2);
      *(undefined2 *)(pbVar3 + 8) = *(undefined2 *)(param_1 + 4);
      *pbVar3 = param_1[6];
      pbVar3[1] = param_1[7];
      *(undefined1 *)(puVar2 + 0x10) = 6;
    }
  }
_L64:
  (**(code **)(_r_ip_funcs_p + 0x4b8))(param_2,iVar1,*(code **)(_r_ip_funcs_p + 0x4b8));
  return 0;
}

