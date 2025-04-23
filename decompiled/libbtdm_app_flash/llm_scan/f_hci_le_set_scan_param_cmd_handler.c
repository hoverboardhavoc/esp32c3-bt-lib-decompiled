/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llm_scan.o -> f_hci_le_set_scan_param_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 f_hci_le_set_scan_param_cmd_handler(byte *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  byte *pbVar4;
  int *piVar5;
  byte abStack_21 [9];
  
  if (*(char *)(_p_llm_env + 0xd7) == '\x02') {
_L13:
    iVar1 = 0xc;
  }
  else {
    *(undefined1 *)(_p_llm_env + 0xd7) = 1;
    uVar3 = 0;
    while( true ) {
      abStack_21[0] = (byte)uVar3;
      iVar1 = r_sdk_config_get_opts();
      uVar3 = (uint)abStack_21[0];
      if (*(byte *)(iVar1 + 0xd) <= uVar3) break;
      if ((byte)(*(char *)(*(int *)(_p_llm_env + 8) + uVar3 * 0x44 + 0x40) - 6U) < 3) break;
      uVar3 = uVar3 + 1 & 0xff;
    }
    iVar1 = r_sdk_config_get_opts();
    if ((uint)abStack_21[0] < (uint)*(byte *)(iVar1 + 0xd)) {
      if (*(char *)((uint)abStack_21[0] * 0x44 + *(int *)(_p_llm_env + 8) + 0x40) != '\x06')
      goto _L13;
    }
    else {
      iVar1 = r_llm_activity_free_get(abStack_21);
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
        iVar1 = r_ke_msg_alloc(0,0,0,0x10);
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
  r_llm_cmd_cmp_send(param_2,iVar1);
  return 0;
}

