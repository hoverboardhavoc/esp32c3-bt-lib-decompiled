/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld_adv.o -> r_lld_adv_stop
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_lld_adv_stop(int param_1)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  iVar4 = *(int *)(&lld_adv_env + param_1 * 4);
  if (iVar4 == 0) {
    uVar2 = 0xc;
  }
  else {
    if (*(char *)(iVar4 + 0x89) == '\0') {
      r_lld_adv_end_hack(1,0);
    }
    else if (*(char *)(iVar4 + 0x89) == '\x01') {
      bVar1 = *(byte *)(iVar4 + 0x87);
      iVar3 = r_emi_get_mem_addr_by_offset(0x400);
      *(undefined2 *)((uint)bVar1 * 0x5a + 0x20 + iVar3) = 1;
      _DAT_60031000 = _DAT_60031000 & 0xfdffffff | 0x2000000;
      *(undefined1 *)(iVar4 + 0x89) = 2;
    }
    uVar2 = 0;
  }
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return uVar2;
}

