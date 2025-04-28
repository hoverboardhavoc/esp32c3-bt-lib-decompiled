/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llm_adv.o -> hci_le_rd_nb_supp_adv_sets_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_rd_nb_supp_adv_sets_cmd_handler(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  undefined1 *puVar3;
  
  iVar2 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar2 + 0x18) == '\0') {
    puVar3 = (undefined1 *)r_ke_msg_alloc(0x1101,0,param_1,2);
    puVar3[1] = 0;
    *puVar3 = 0xc;
    r_hci_send_2_host();
    return 0;
  }
  puVar3 = (undefined1 *)r_ke_msg_alloc(0x1101,0,param_1,2);
  puVar3[1] = 0;
  if (*(char *)(_p_llm_env + 0xd7) == '\x01') {
    *puVar3 = 0xc;
  }
  else {
    *(undefined1 *)(_p_llm_env + 0xd7) = 2;
    *puVar3 = 0;
    for (uVar1 = 0; iVar2 = r_sdk_config_get_opts(), uVar1 < *(byte *)(iVar2 + 0xd);
        uVar1 = uVar1 + 1 & 0xff) {
      if (*(byte *)(*(int *)(_p_llm_env + 8) + uVar1 * 0x44 + 0x40) < 4) {
        puVar3[1] = puVar3[1] + '\x01';
      }
    }
  }
  r_hci_send_2_host(puVar3);
  return 0;
}

