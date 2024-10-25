/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld_test.o -> r_lld_test_stop
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_lld_test_stop(void)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined2 uVar4;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  iVar3 = _lld_test_env;
  uVar1 = 0xc;
  if (_lld_test_env != 0) {
    (*_rwip_rf)(1,_rwip_rf);
    _DAT_60031000 = _DAT_60031000 & 0xffffbfff;
    if (*(char *)(iVar3 + 0x2a) == '\0') {
      r_sch_arb_remove(iVar3,0);
      _DAT_600310d0 = 0;
      puVar2 = (undefined1 *)r_ke_msg_alloc(0x20a,0,0xff,4);
      *puVar2 = 0;
      uVar4 = 0;
      if (*(char *)(iVar3 + 0x26) == '\0') {
        iVar3 = r_emi_get_mem_addr_by_offset(0x400);
        uVar4 = *(undefined2 *)(iVar3 + 0x4a);
      }
      *(undefined2 *)(puVar2 + 2) = uVar4;
      r_ke_msg_send(puVar2);
      r_lld_test_cleanup(0);
    }
    else if (*(char *)(iVar3 + 0x2a) == '\x01') {
      _DAT_60031000 = _DAT_60031000 | 0x4000000;
      *(undefined1 *)(iVar3 + 0x2a) = 2;
    }
    uVar1 = 0;
  }
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return uVar1;
}

