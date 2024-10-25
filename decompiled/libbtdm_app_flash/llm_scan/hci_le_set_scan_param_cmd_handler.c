/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llm_scan.o -> hci_le_set_scan_param_cmd_handler
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
  byte abStack_21 [9];
  
  iVar1 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar1 + 0x23) == '\0') {
    r_llm_cmd_cmp_send(param_2,0xc);
    return 0;
  }
  if (*(char *)(_p_llm_env + 0xd7) == '\x02') {
_L15:
    iVar1 = 0xc;
  }
  else {
    *(undefined1 *)(_p_llm_env + 0xd7) = 1;
    abStack_21[0] = 0;
    while( true ) {
      iVar1 = r_sdk_config_get_opts();
      if (((uint)*(byte *)(iVar1 + 0xd) <= (uint)abStack_21[0]) ||
         ((byte)(*(char *)(*(int *)(_p_llm_env + 8) + (uint)abStack_21[0] * 0x44 + 0x40) - 6U) < 3))
      break;
      abStack_21[0] = abStack_21[0] + 1;
    }
    iVar1 = r_sdk_config_get_opts();
    if ((uint)abStack_21[0] < (uint)*(byte *)(iVar1 + 0xd)) {
      if (*(char *)((uint)abStack_21[0] * 0x44 + *(int *)(_p_llm_env + 8) + 0x40) != '\x06')
      goto _L15;
    }
    else {
      iVar1 = r_llm_activity_free_get(abStack_21);
      if (iVar1 != 0) goto _L24;
      *(undefined1 *)(*(int *)(_p_llm_env + 8) + (uint)abStack_21[0] * 0x44 + 0x40) = 6;
    }
    iVar1 = 0x12;
    if (((((*(ushort *)(param_1 + 4) <= *(ushort *)(param_1 + 2)) && (*param_1 < 2)) &&
         ((ushort)(*(ushort *)(param_1 + 4) - 4) < 0x3ffd)) &&
        (((ushort)(*(ushort *)(param_1 + 2) - 4) < 0x3ffd && (param_1[6] < 4)))) &&
       ((param_1[7] < 4 && ((*(char *)(_p_llm_env + 0xc6) != '\0' || (param_1[7] < 2)))))) {
      piVar4 = (int *)(*(int *)(_p_llm_env + 8) + (uint)abStack_21[0] * 0x44);
      if (*piVar4 == 0) {
        iVar1 = r_ke_msg_alloc(0,0,0,0x10);
        *piVar4 = iVar1;
      }
      iVar1 = 0;
      puVar2 = (undefined4 *)(*(int *)(_p_llm_env + 8) + (uint)abStack_21[0] * 0x44);
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
_L24:
  r_llm_cmd_cmp_send(param_2,iVar1);
  return 0;
}

