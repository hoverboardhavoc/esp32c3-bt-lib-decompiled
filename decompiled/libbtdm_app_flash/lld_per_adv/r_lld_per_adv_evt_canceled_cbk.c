/*
 * Last changed at upstream commit aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * https://github.com/espressif/esp32c3-bt-lib/commit/aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * Upstream date: 2025-03-20 20:31:24 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(d74042a8)
 * Source: libbtdm_app_flash -> lld_per_adv.o -> r_lld_per_adv_evt_canceled_cbk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_per_adv_evt_canceled_cbk(int param_1)

{
  int iVar1;
  char cVar2;
  int iVar3;
  
  if (param_1 == 0) {
    r_assert_err("lld_per_adv.c",0x3c0);
    return;
  }
  if (*(char *)(param_1 + 0x53) != '\0') {
    r_assert_err(0,"lld_per_adv.c",0x3b6);
  }
  *(char *)(param_1 + 0x16) = *(char *)(param_1 + 0x16) + rwip_priority;
  iVar1 = *(int *)(&lld_per_adv_env + (uint)*(byte *)(param_1 + 0x52) * 4);
  *(uint *)(iVar1 + 4) = *(int *)(iVar1 + 4) + *(int *)(iVar1 + 0x40) & 0xfffffff;
  *(short *)(iVar1 + 0x4c) = *(short *)(iVar1 + 0x4c) + 1;
  iVar3 = r_lld_read_clock();
  while ((iVar3 - *(int *)(iVar1 + 4) & 0xfffffffU) < 0x7ffffff) {
    *(uint *)(iVar1 + 4) = *(int *)(iVar1 + 4) + *(int *)(iVar1 + 0x40) & 0xfffffff;
    *(short *)(iVar1 + 0x4c) = *(short *)(iVar1 + 0x4c) + 1;
  }
  cVar2 = '\x0f';
  do {
    iVar3 = r_sch_arb_insert(iVar1);
    if (iVar3 == 0) {
      *(undefined1 *)(iVar1 + 0x53) = 0;
      return;
    }
    cVar2 = cVar2 + -1;
    *(char *)(iVar1 + 0x16) = *(char *)(iVar1 + 0x16) + DAT_0001301b;
    *(uint *)(iVar1 + 4) = *(int *)(iVar1 + 4) + *(int *)(iVar1 + 0x40) & 0xfffffff;
    *(short *)(iVar1 + 0x4c) = *(short *)(iVar1 + 0x4c) + 1;
  } while (cVar2 != '\0');
  r_assert_param("lld_per_adv.c",0x13e);
  return;
}

