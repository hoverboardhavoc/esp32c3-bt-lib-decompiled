/*
 * Last changed at upstream commit e668c2d101ee46ee1950819607694fb852aecae0
 * https://github.com/espressif/esp32c3-bt-lib/commit/e668c2d101ee46ee1950819607694fb852aecae0
 * Upstream date: 2025-03-14 11:07:43 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(6e312587)
 * Source: libbtdm_app_flash -> lld_test.o -> r_lld_test_frm_cbk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_test_frm_cbk(undefined4 param_1,int param_2)

{
  bool bVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined4 uVar6;
  code cVar7;
  undefined2 uVar8;
  
  if (param_2 == 1) {
    bVar1 = true;
  }
  else {
    if (param_2 != 0) {
      if (param_2 != 2) {
        r_assert_param(param_1,"lld_test.c",0x238);
        return;
      }
      if (_lld_test_env != 0) {
        uVar6 = 2;
        while (iVar3 = r_lld_rxdesc_check_hack(0,uVar6), iVar3 != 0) {
          uVar6 = r_lld_rxdesc_free();
        }
        return;
      }
      r_assert_err(0,"lld_test.c",0x1df);
      return;
    }
    bVar1 = false;
  }
  if (_lld_test_env == 0) {
    r_assert_err(0,"lld_test.c",0x99);
  }
  iVar3 = _lld_test_env;
  _DAT_600310d0 = 0;
  if ((*(char *)(_lld_test_env + 0x2a) == '\x02') && (*(char *)(_lld_test_env + 0x26) == '\x01')) {
    r_sch_arb_remove(1);
    puVar5 = (undefined1 *)r_ke_msg_alloc(0x20a,0,0xff,4);
    *puVar5 = 0;
    iVar3 = r_emi_get_mem_addr_by_offset(0x400);
    *(undefined2 *)(puVar5 + 2) = *(undefined2 *)(iVar3 + 0x44);
    r_ke_msg_send(puVar5);
    r_lld_test_cleanup(1);
    return;
  }
  if (_lld_test_env == 0) {
    uVar6 = 0x21b;
  }
  else {
    r_sch_arb_remove(_lld_test_env,1);
    bVar2 = DAT_00011015;
    if (*(char *)(iVar3 + 0x2a) == '\x02') {
      puVar5 = (undefined1 *)r_ke_msg_alloc(0x20a,0,0xff,4);
      *puVar5 = 0;
      uVar8 = 0;
      if (*(char *)(iVar3 + 0x26) == '\0') {
        iVar3 = r_emi_get_mem_addr_by_offset(0x400);
        uVar8 = *(undefined2 *)(iVar3 + 0x4a);
      }
      *(undefined2 *)(puVar5 + 2) = uVar8;
      r_ke_msg_send(puVar5);
      r_lld_test_cleanup(1);
      return;
    }
    cVar7 = r_emi_get_mem_addr_by_offset;
    if (bVar1) {
      cVar7 = (code)(*(char *)(iVar3 + 0x16) + DAT_00011015);
    }
    *(code *)(iVar3 + 0x16) = cVar7;
    *(ushort *)(iVar3 + 0x14) = bVar2 & 0xf | 0x6000;
    iVar4 = r_sch_arb_insert(iVar3);
    if (iVar4 == 0) {
      *(undefined1 *)(iVar3 + 0x2a) = 0;
      return;
    }
    uVar6 = 0x215;
  }
  r_assert_err(0,"lld_test.c",uVar6);
  return;
}

