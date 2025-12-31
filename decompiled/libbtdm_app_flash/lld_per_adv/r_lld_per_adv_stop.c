/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
 * Source: libbtdm_app_flash -> lld_per_adv.o -> r_lld_per_adv_stop
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 r_lld_per_adv_stop(int param_1)

{
  byte bVar1;
  undefined1 uVar2;
  undefined1 *puVar3;
  int iVar4;
  int iVar5;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  iVar5 = *(int *)(&lld_per_adv_env + param_1 * 4);
  if (iVar5 == 0) {
    r_ble_log_internal_x1(0x8004010d,param_1);
    uVar2 = 0xc;
  }
  else {
    r_ble_log_internal_x1
              (0x4004010c,
               (uint)*(ushort *)(iVar5 + 0x4c) | param_1 << 0x10 |
               (uint)*(byte *)(iVar5 + 0x53) << 0x18);
    if (*(char *)(iVar5 + 0x53) == '\0') {
      r_sch_arb_remove(iVar5,0);
      puVar3 = (undefined1 *)r_ke_msg_alloc(0x208,0,0xff,2);
      *puVar3 = (char)param_1;
      puVar3[1] = 0;
      r_ke_msg_send();
      r_lld_per_adv_cleanup(param_1);
      uVar2 = 0;
    }
    else {
      if (*(char *)(iVar5 + 0x53) == '\x01') {
        bVar1 = *(byte *)(iVar5 + 0x52);
        iVar4 = r_emi_get_mem_addr_by_offset(0x400);
        *(undefined2 *)((uint)bVar1 * 0x5a + 0x20 + iVar4) = 1;
        _DAT_60031000 = _DAT_60031000 & 0xfdffffff | 0x2000000;
        *(undefined1 *)(iVar5 + 0x53) = 2;
      }
      uVar2 = 0;
    }
  }
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return uVar2;
}

