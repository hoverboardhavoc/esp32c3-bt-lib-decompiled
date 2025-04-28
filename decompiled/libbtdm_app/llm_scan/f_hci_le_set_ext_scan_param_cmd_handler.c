/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llm_scan.o -> f_hci_le_set_ext_scan_param_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 f_hci_le_set_ext_scan_param_cmd_handler(byte *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  byte bVar3;
  char cVar4;
  byte *pbVar5;
  int iVar6;
  byte bVar7;
  uint uVar8;
  byte abStack_21 [5];
  
  if (*(char *)(_p_llm_env + 0xd7) == '\x01') {
_L38:
    iVar2 = 0xc;
  }
  else {
    *(undefined1 *)(_p_llm_env + 0xd7) = 2;
    uVar8 = 0;
    while( true ) {
      abStack_21[0] = (byte)uVar8;
      iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
      uVar8 = (uint)abStack_21[0];
      if (*(byte *)(iVar2 + 0xd) <= uVar8) break;
      if ((byte)(*(char *)(*(int *)(_p_llm_env + 8) + uVar8 * 0x44 + 0x40) - 6U) < 3) break;
      uVar8 = uVar8 + 1 & 0xff;
    }
    iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
    if ((uint)abStack_21[0] < (uint)*(byte *)(iVar2 + 0xd)) {
      if (*(char *)((uint)abStack_21[0] * 0x44 + *(int *)(_p_llm_env + 8) + 0x40) != '\x06')
      goto _L38;
    }
    else {
      iVar2 = (**(code **)(_r_ip_funcs_p + 0x4ac))(abStack_21,*(code **)(_r_ip_funcs_p + 0x4ac));
      if (iVar2 != 0) goto _L45;
    }
    bVar7 = param_1[2];
    if (bVar7 != 1) {
      if (bVar7 == 4) {
        bVar7 = 1;
      }
      else {
        iVar2 = 0x12;
        if (bVar7 != 5) goto _L45;
        bVar7 = 2;
      }
    }
    pbVar5 = param_1 + 4;
    cVar4 = '\0';
    do {
      if ((((*(ushort *)(pbVar5 + 2) < *(ushort *)(pbVar5 + 4)) || (1 < *pbVar5)) ||
          (*(ushort *)(pbVar5 + 4) < 4)) || (*(ushort *)(pbVar5 + 2) < 4)) goto _L59;
      bVar3 = cVar4 + 1;
      pbVar5 = pbVar5 + 6;
      cVar4 = '\x01';
    } while (bVar3 < bVar7);
    if ((*param_1 < 4) && (param_1[1] < 4)) {
      iVar2 = *(int *)(*(int *)(_p_llm_env + 8) + (uint)abStack_21[0] * 0x44);
      if (iVar2 != 0) {
        (**(code **)(_r_modules_funcs_p + 0xd8))(iVar2 + -0xc,*(code **)(_r_modules_funcs_p + 0xd8))
        ;
        *(undefined4 *)(*(int *)(_p_llm_env + 8) + (uint)abStack_21[0] * 0x44) = 0;
      }
      iVar2 = 0;
      iVar6 = *(int *)(_p_llm_env + 8);
      *(byte **)((uint)abStack_21[0] * 0x44 + iVar6) = param_1;
      uVar1 = 1;
      *(undefined1 *)(iVar6 + (uint)abStack_21[0] * 0x44 + 0x40) = 6;
      goto _L50;
    }
_L59:
    iVar2 = 0x12;
  }
_L45:
  uVar1 = 0;
_L50:
  (**(code **)(_r_ip_funcs_p + 0x4b8))(param_2,iVar2,*(code **)(_r_ip_funcs_p + 0x4b8));
  return uVar1;
}

