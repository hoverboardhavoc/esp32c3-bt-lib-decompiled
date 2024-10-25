/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llm_adv.o -> f_hci_le_set_adv_set_rand_addr_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 f_hci_le_set_adv_set_rand_addr_cmd_handler(undefined1 *param_1,undefined4 param_2)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  if (*(char *)(_p_llm_env + 0xd7) != '\x01') {
    *(undefined1 *)(_p_llm_env + 0xd7) = 2;
    uVar4 = 0x42;
    uVar2 = r_llm_adv_hdl_to_id(*param_1,0);
    iVar5 = *(int *)(*(int *)(_p_llm_env + 8) + uVar2 * 0x44);
    iVar3 = r_sdk_config_get_opts();
    if (*(byte *)(iVar3 + 0xd) <= uVar2) goto _L396;
    iVar3 = *(int *)(_p_llm_env + 8) + uVar2 * 0x44;
    cVar1 = *(char *)(iVar3 + 0x40);
    if ((cVar1 != '\x02') || (*(short *)(iVar5 + 2) == 0)) {
      memcpy((void *)(iVar3 + 4),param_1 + 1,6);
      uVar4 = 0;
      if (cVar1 == '\x02') {
        r_lld_adv_rand_addr_update(uVar2,*(undefined4 *)(param_1 + 1),*(undefined2 *)(param_1 + 5));
      }
      goto _L396;
    }
  }
  uVar4 = 0xc;
_L396:
  r_llm_cmd_cmp_send(param_2,uVar4);
  return 0;
}

