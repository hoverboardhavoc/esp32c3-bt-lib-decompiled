/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
  int iVar2;
  uint uVar3;
  byte *pbVar4;
  int *piVar5;
  byte abStack_21 [5];
  
  iVar1 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
  if (*(char *)(iVar1 + 0x23) == '\0') {
    (**(code **)(_r_ip_funcs_p + 0x4b8))(param_2,0xc,*(code **)(_r_ip_funcs_p + 0x4b8));
    return 0;
  }
  if (*(char *)(_p_llm_env + 0xd7) == '\x02') {
_L13:
    iVar1 = 0xc;
  }
  else {
    *(undefined1 *)(_p_llm_env + 0xd7) = 1;
    uVar3 = 0;
    while( true ) {
      abStack_21[0] = (byte)uVar3;
      iVar1 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
      uVar3 = (uint)abStack_21[0];
      if ((*(byte *)(iVar1 + 0xd) <= uVar3) ||
         ((byte)(*(char *)(*(int *)(_p_llm_env + 8) + uVar3 * 0x44 + 0x40) - 6U) < 3)) break;
      uVar3 = uVar3 + 1 & 0xff;
    }
    iVar1 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
    if ((uint)abStack_21[0] < (uint)*(byte *)(iVar1 + 0xd)) {
      if (*(char *)((uint)abStack_21[0] * 0x44 + *(int *)(_p_llm_env + 8) + 0x40) != '\x06')
      goto _L13;
    }
    else {
      iVar1 = (**(code **)(_r_ip_funcs_p + 0x4ac))(abStack_21,*(code **)(_r_ip_funcs_p + 0x4ac));
      if (iVar1 != 0) goto _L22;
      *(undefined1 *)(*(int *)(_p_llm_env + 8) + (uint)abStack_21[0] * 0x44 + 0x40) = 6;
    }
    iVar1 = 0x12;
    if (((((*(ushort *)(param_1 + 4) <= *(ushort *)(param_1 + 2)) && (*param_1 < 2)) &&
         ((ushort)(*(ushort *)(param_1 + 4) - 4) < 0x3ffd)) &&
        (((ushort)(*(ushort *)(param_1 + 2) - 4) < 0x3ffd && (param_1[6] < 4)))) &&
       ((param_1[7] < 4 && ((*(char *)(_p_llm_env + 0xc6) != '\0' || (param_1[7] < 2)))))) {
      piVar5 = (int *)(*(int *)(_p_llm_env + 8) + (uint)abStack_21[0] * 0x44);
      if (*piVar5 == 0) {
        iVar1 = (**(code **)(_r_modules_funcs_p + 200))
                          (0,0,0,0x10,*(code **)(_r_modules_funcs_p + 200));
        *piVar5 = iVar1;
      }
      iVar2 = *(int *)(_p_llm_env + 8);
      iVar1 = 0;
      pbVar4 = *(byte **)((uint)abStack_21[0] * 0x44 + iVar2);
      pbVar4[2] = 1;
      pbVar4[4] = *param_1;
      *(undefined2 *)(pbVar4 + 6) = *(undefined2 *)(param_1 + 2);
      *(undefined2 *)(pbVar4 + 8) = *(undefined2 *)(param_1 + 4);
      *pbVar4 = param_1[6];
      pbVar4[1] = param_1[7];
      *(undefined1 *)(iVar2 + (uint)abStack_21[0] * 0x44 + 0x40) = 6;
    }
  }
_L22:
  (**(code **)(_r_ip_funcs_p + 0x4b8))(param_2,iVar1,*(code **)(_r_ip_funcs_p + 0x4b8));
  return 0;
}

