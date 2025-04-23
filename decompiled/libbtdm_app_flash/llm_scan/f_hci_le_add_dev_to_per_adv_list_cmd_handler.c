/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
  undefined4 uVar3;
  byte *__src;
  
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
             (((int)(uint)*(ushort *)(iVar2 + 0x2a) >> (param_1[7] & 0x1f) & 1U) != 0)) goto _L308;
        }
        else {
          uVar1 = r_llm_dev_list_empty_entry();
          uVar3 = 7;
          if (uVar1 == 0xc) goto _L307;
        }
        memcpy((void *)(_p_llm_env + uVar1 * 10 + 0x24),__src,6);
        iVar2 = _p_llm_env + uVar1 * 10;
        *(byte *)(iVar2 + 0x2c) = *param_1;
        *(ushort *)(iVar2 + 0x2a) = *(ushort *)(iVar2 + 0x2a) | (ushort)(1 << (param_1[7] & 0x1f));
        *(byte *)(iVar2 + 0x2d) = *(byte *)(iVar2 + 0x2d) | 5;
        iVar2 = r_llm_is_dev_synced(__src);
        if (iVar2 == 0) {
          r_lld_per_adv_list_add(uVar1,__src,*param_1,param_1[7]);
        }
        uVar3 = 0;
        goto _L307;
      }
    }
    uVar3 = 0xc;
  }
  else {
_L308:
    uVar3 = 0x12;
  }
_L307:
  r_llm_cmd_cmp_send(param_2,uVar3);
  return 0;
}

