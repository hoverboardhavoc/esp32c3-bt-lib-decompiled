/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llm_scan.o -> f_hci_le_add_dev_to_per_adv_list_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 f_hci_le_add_dev_to_per_adv_list_cmd_handler(byte *param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  byte *__src;
  undefined4 uVar3;
  
  if ((param_1[7] < 0x10) && (*param_1 < 2)) {
    if (*(char *)(_p_llm_env + 0xd7) != '\x01') {
      *(undefined1 *)(_p_llm_env + 0xd7) = 2;
      uVar1 = r_llm_activity_syncing_get();
      iVar2 = r_sdk_config_get_opts();
      if (*(byte *)(iVar2 + 0xd) <= uVar1) {
        __src = param_1 + 1;
        uVar1 = r_llm_dev_list_search(__src,*param_1);
        if (uVar1 < 0xc) {
          iVar2 = _p_llm_env + uVar1 * 10;
          if (((*(byte *)(iVar2 + 0x2d) & 4) != 0) &&
             (((int)(uint)*(ushort *)(iVar2 + 0x2a) >> (param_1[7] & 0x1f) & 1U) != 0)) goto _L300;
        }
        else {
          uVar1 = r_llm_dev_list_empty_entry();
          uVar3 = 7;
          if (uVar1 == 0xc) goto _L299;
        }
        memcpy((void *)(_p_llm_env + uVar1 * 10 + 0x24),__src,6);
        iVar2 = _p_llm_env + uVar1 * 10;
        *(byte *)(iVar2 + 0x2c) = *param_1;
        *(ushort *)(iVar2 + 0x2a) = (ushort)(1 << (param_1[7] & 0x1f)) | *(ushort *)(iVar2 + 0x2a);
        uVar3 = 0;
        *(byte *)(iVar2 + 0x2d) = *(byte *)(iVar2 + 0x2d) | 5;
        iVar2 = r_llm_is_dev_synced(__src);
        if (iVar2 == 0) {
          r_lld_per_adv_list_add(uVar1,__src,*param_1,param_1[7]);
        }
        goto _L299;
      }
    }
    uVar3 = 0xc;
  }
  else {
_L300:
    uVar3 = 0x12;
  }
_L299:
  r_llm_cmd_cmp_send(param_2,uVar3);
  return 0;
}

