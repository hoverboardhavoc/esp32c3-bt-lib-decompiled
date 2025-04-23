/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llm_adv.o -> f_hci_le_rmv_adv_set_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 f_hci_le_rmv_adv_set_cmd_handler(undefined1 *param_1,undefined4 param_2)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined1 auStack_24 [8];
  
  if (*(char *)(_p_llm_env + 0xd7) != '\x01') {
    *(undefined1 *)(_p_llm_env + 0xd7) = 2;
    iVar2 = r_llm_adv_hdl_to_id(*param_1,auStack_24);
    uVar3 = 0x42;
    if (iVar2 == 0xff) goto _L811;
    iVar4 = *(int *)(_p_llm_env + 8) + iVar2 * 0x44;
    if (*(char *)(iVar4 + 0x40) == '\x01') {
      bVar1 = *(byte *)(iVar4 + 0x3d);
      iVar4 = r_sdk_config_get_opts(0x42);
      if ((*(byte *)(iVar4 + 0xd) <= bVar1) ||
         (*(char *)(*(int *)(_p_llm_env + 8) +
                    (uint)*(byte *)(iVar2 * 0x44 + *(int *)(_p_llm_env + 8) + 0x3d) * 0x44 + 0x40)
          == '\n')) {
        r_llm_adv_set_release_hack(iVar2);
        uVar3 = 0;
        goto _L811;
      }
    }
  }
  uVar3 = 0xc;
_L811:
  r_llm_cmd_cmp_send(param_2,uVar3);
  return 0;
}

