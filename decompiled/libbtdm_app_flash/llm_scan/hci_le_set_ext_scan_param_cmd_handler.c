/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llm_scan.o -> hci_le_set_ext_scan_param_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_set_ext_scan_param_cmd_handler(byte *param_1,undefined4 param_2)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  byte *pbVar6;
  undefined4 *puVar7;
  byte abStack_21 [9];
  
  iVar3 = r_sdk_config_get_opts_ext();
  if ((*(char *)(iVar3 + 0x18) == '\0') ||
     (iVar3 = r_sdk_config_get_opts_ext(), *(char *)(iVar3 + 0x23) == '\0')) {
    r_llm_cmd_cmp_send(param_2,0xc);
    return 0;
  }
  if (*(char *)(_p_llm_env + 0xd7) == '\x01') {
_L40:
    iVar3 = 0xc;
  }
  else {
    *(undefined1 *)(_p_llm_env + 0xd7) = 2;
    abStack_21[0] = 0;
    while( true ) {
      iVar3 = r_sdk_config_get_opts();
      if (((uint)*(byte *)(iVar3 + 0xd) <= (uint)abStack_21[0]) ||
         ((byte)(*(char *)(*(int *)(_p_llm_env + 8) + (uint)abStack_21[0] * 0x44 + 0x40) - 6U) < 3))
      break;
      abStack_21[0] = abStack_21[0] + 1;
    }
    iVar3 = r_sdk_config_get_opts();
    if ((uint)abStack_21[0] < (uint)*(byte *)(iVar3 + 0xd)) {
      if (*(char *)((uint)abStack_21[0] * 0x44 + *(int *)(_p_llm_env + 8) + 0x40) != '\x06')
      goto _L40;
    }
    else {
      iVar3 = r_llm_activity_free_get(abStack_21);
      if (iVar3 != 0) goto _L47;
    }
    bVar1 = param_1[2];
    if ((bVar1 == 1) || (bVar1 == 4)) {
      uVar5 = 1;
    }
    else {
      iVar3 = 0x12;
      uVar5 = 2;
      if (bVar1 != 5) goto _L47;
    }
    pbVar6 = param_1 + 4;
    iVar3 = 0;
    do {
      if ((((*(ushort *)(pbVar6 + 2) < *(ushort *)(pbVar6 + 4)) || (1 < *pbVar6)) ||
          (*(ushort *)(pbVar6 + 4) < 4)) || (*(ushort *)(pbVar6 + 2) < 4)) goto _L62;
      uVar4 = iVar3 + 1;
      pbVar6 = pbVar6 + 6;
      iVar3 = 1;
    } while (uVar4 < uVar5);
    if ((*param_1 < 4) && (param_1[1] < 4)) {
      iVar3 = *(int *)(*(int *)(_p_llm_env + 8) + (uint)abStack_21[0] * 0x44);
      if (iVar3 != 0) {
        r_ke_msg_free(iVar3 + -0xc);
        *(undefined4 *)(*(int *)(_p_llm_env + 8) + (uint)abStack_21[0] * 0x44) = 0;
      }
      iVar3 = 0;
      uVar2 = 1;
      puVar7 = (undefined4 *)(*(int *)(_p_llm_env + 8) + (uint)abStack_21[0] * 0x44);
      *puVar7 = param_1;
      *(undefined1 *)(puVar7 + 0x10) = 6;
      goto _L52;
    }
_L62:
    iVar3 = 0x12;
  }
_L47:
  uVar2 = 0;
_L52:
  r_llm_cmd_cmp_send(param_2,iVar3);
  return uVar2;
}

