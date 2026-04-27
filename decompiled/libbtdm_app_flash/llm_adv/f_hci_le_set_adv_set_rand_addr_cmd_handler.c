/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> llm_adv.o -> f_hci_le_set_adv_set_rand_addr_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 f_hci_le_set_adv_set_rand_addr_cmd_handler(undefined1 *param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  
  if (*(char *)(_p_llm_env + 0xd7) != '\x01') {
    *(undefined1 *)(_p_llm_env + 0xd7) = 2;
    uVar4 = 0x42;
    uVar1 = r_llm_adv_hdl_to_id(*param_1,0);
    iVar2 = r_sdk_config_get_opts();
    if (*(byte *)(iVar2 + 0xd) <= uVar1) goto _L445;
    piVar3 = (int *)(*(int *)(_p_llm_env + 8) + uVar1 * 0x44);
    iVar2 = piVar3[0x10];
    if (((char)iVar2 != '\x02') || ((*(ushort *)(*piVar3 + 2) & 1) == 0)) {
      memcpy(piVar3 + 1,param_1 + 1,6);
      uVar4 = 0;
      if ((char)iVar2 == '\x02') {
        r_lld_adv_rand_addr_update(uVar1,*(undefined4 *)(param_1 + 1),*(undefined2 *)(param_1 + 5));
      }
      goto _L445;
    }
  }
  uVar4 = 0xc;
_L445:
  r_llm_cmd_cmp_send(param_2,uVar4);
  return 0;
}

