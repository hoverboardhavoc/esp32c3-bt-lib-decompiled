/*
 * Last changed at upstream commit aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * https://github.com/espressif/esp32c3-bt-lib/commit/aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * Upstream date: 2025-03-20 20:31:24 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(d74042a8)
 * Source: libbtdm_app_flash -> lld_test.o -> r_lld_test_frm_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_test_frm_isr(int param_1)

{
  byte bVar1;
  undefined1 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  code cVar6;
  undefined2 uVar7;
  
  iVar3 = _lld_test_env;
  if (_lld_test_env == 0) {
    uVar5 = 0x21b;
  }
  else {
    r_sch_arb_remove(_lld_test_env,1);
    bVar1 = DAT_00011015;
    if (*(char *)(iVar3 + 0x2a) == '\x02') {
      puVar2 = (undefined1 *)r_ke_msg_alloc(0x20a,0,0xff,4);
      *puVar2 = 0;
      uVar7 = 0;
      if (*(char *)(iVar3 + 0x26) == '\0') {
        iVar3 = r_emi_get_mem_addr_by_offset(0x400);
        uVar7 = *(undefined2 *)(iVar3 + 0x4a);
      }
      *(undefined2 *)(puVar2 + 2) = uVar7;
      r_ke_msg_send(puVar2);
      r_lld_test_cleanup(1);
      return;
    }
    cVar6 = r_emi_get_mem_addr_by_offset;
    if (param_1 != 0) {
      cVar6 = (code)(*(char *)(iVar3 + 0x16) + DAT_00011015);
    }
    *(code *)(iVar3 + 0x16) = cVar6;
    *(ushort *)(iVar3 + 0x14) = bVar1 & 0xf | 0x6000;
    iVar4 = r_sch_arb_insert(iVar3);
    if (iVar4 == 0) {
      *(undefined1 *)(iVar3 + 0x2a) = 0;
      return;
    }
    uVar5 = 0x215;
  }
  r_assert_err(0,"lld_test.c",uVar5);
  return;
}

