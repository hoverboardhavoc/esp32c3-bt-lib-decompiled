/*
 * Last changed at upstream commit e668c2d101ee46ee1950819607694fb852aecae0
 * https://github.com/espressif/esp32c3-bt-lib/commit/e668c2d101ee46ee1950819607694fb852aecae0
 * Upstream date: 2025-03-14 11:07:43 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(6e312587)
 * Source: libbtdm_app_flash -> lld_per_adv.o -> r_lld_per_adv_stop
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_lld_per_adv_stop(int param_1)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  int iVar5;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  iVar2 = *(int *)(&lld_per_adv_env + param_1 * 4);
  uVar3 = 0xc;
  if (iVar2 != 0) {
    if (*(char *)(iVar2 + 0x53) == '\0') {
      r_sch_arb_remove(iVar2,0);
      puVar4 = (undefined1 *)r_ke_msg_alloc(0x208,0,0xff,2);
      *puVar4 = (char)param_1;
      puVar4[1] = 0;
      r_ke_msg_send();
      r_lld_per_adv_cleanup(param_1);
    }
    else if (*(char *)(iVar2 + 0x53) == '\x01') {
      bVar1 = *(byte *)(iVar2 + 0x52);
      iVar5 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)((uint)bVar1 * 0x5a + 0x20 + iVar5) = 1;
      _DAT_60031000 = _DAT_60031000 & 0xfdffffff | 0x2000000;
      *(undefined1 *)(iVar2 + 0x53) = 2;
    }
    uVar3 = 0;
  }
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return uVar3;
}

