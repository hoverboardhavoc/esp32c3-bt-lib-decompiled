/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_per_adv.o -> r_lld_per_adv_stop
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 r_lld_per_adv_stop(uint param_1)

{
  byte bVar1;
  undefined1 uVar2;
  int iVar3;
  undefined1 *puVar4;
  int iVar5;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  iVar5 = *(int *)(&lld_per_adv_env + param_1 * 4);
  if (iVar5 == 0) {
    iVar5 = r_sdk_config_get_opts_ext();
    if ((*(uint *)(iVar5 + 0x28) & 0x40) != 0) {
      iVar5 = r_sdk_config_get_opts_ext();
      if (*(byte *)(iVar5 + 0x2c) < 3) {
        r_ble_log_internal_x1(0x40080003,param_1);
      }
    }
    uVar2 = 0xc;
  }
  else {
    iVar3 = r_sdk_config_get_opts_ext();
    if ((*(uint *)(iVar3 + 0x28) & 0x40) != 0) {
      iVar3 = r_sdk_config_get_opts_ext();
      if (*(byte *)(iVar3 + 0x2c) < 3) {
        r_ble_log_internal_x1
                  (0x40080001,
                   (uint)*(ushort *)(iVar5 + 0x4c) << 0x10 | (uint)*(byte *)(iVar5 + 0x53) << 8 |
                   param_1);
      }
    }
    if (*(char *)(iVar5 + 0x53) == '\0') {
      r_sch_arb_remove(iVar5,0);
      puVar4 = (undefined1 *)r_ke_msg_alloc(0x208,0,0xff,2);
      *puVar4 = (char)param_1;
      puVar4[1] = 0;
      r_ke_msg_send();
      r_lld_per_adv_cleanup(param_1);
      uVar2 = 0;
    }
    else {
      if (*(char *)(iVar5 + 0x53) == '\x01') {
        bVar1 = *(byte *)(iVar5 + 0x52);
        iVar3 = r_emi_get_mem_addr_by_offset(0x400);
        *(undefined2 *)((uint)bVar1 * 0x5a + 0x20 + iVar3) = 1;
        _DAT_60031000 = _DAT_60031000 & 0xfdffffff | 0x2000000;
        *(undefined1 *)(iVar5 + 0x53) = 2;
      }
      uVar2 = 0;
    }
  }
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return uVar2;
}

