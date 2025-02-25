/*
 * Last changed at upstream commit 2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * https://github.com/espressif/esp32c3-bt-lib/commit/2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * Upstream date: 2025-02-25 15:16:47 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(723439d)
 * Source: libbtdm_app_flash -> lld_adv.o -> r_lld_adv_stop
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_lld_adv_stop(uint param_1)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  iVar2 = *(int *)(&lld_adv_env + param_1 * 4);
  uVar3 = 0xc;
  if (iVar2 != 0) {
    iVar4 = r_sdk_config_get_opts_ext();
    if ((*(uint *)(iVar4 + 0x28) & 4) != 0) {
      iVar4 = r_sdk_config_get_opts_ext();
      if (*(byte *)(iVar4 + 0x2c) < 3) {
        r_ble_log_internal_x1(0x40000001,(uint)*(byte *)(iVar2 + 0x89) << 8 | param_1);
      }
    }
    if (*(char *)(iVar2 + 0x89) == '\0') {
      r_lld_adv_end_hack(param_1,1,0);
    }
    else if (*(char *)(iVar2 + 0x89) == '\x01') {
      bVar1 = *(byte *)(iVar2 + 0x87);
      iVar4 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)((uint)bVar1 * 0x5a + 0x20 + iVar4) = 1;
      _DAT_60031000 = _DAT_60031000 & 0xfdffffff | 0x2000000;
      *(undefined1 *)(iVar2 + 0x89) = 2;
    }
    uVar3 = 0;
  }
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return uVar3;
}

