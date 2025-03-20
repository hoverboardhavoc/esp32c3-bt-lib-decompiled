/*
 * Last changed at upstream commit aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * https://github.com/espressif/esp32c3-bt-lib/commit/aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * Upstream date: 2025-03-20 20:31:24 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(d74042a8)
 * Source: libbtdm_app_flash -> lld_per_adv.o -> r_lld_per_adv_frm_skip_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_per_adv_frm_skip_isr(int param_1)

{
  undefined1 uVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  undefined1 *puVar5;
  
  iVar2 = *(int *)(&lld_per_adv_env + param_1 * 4);
  if (iVar2 == 0) {
    r_assert_err(0,"lld_per_adv.c",0x465);
    return;
  }
  if (1 < (byte)(*(char *)(iVar2 + 0x53) - 1U)) {
    r_assert_err(0,"lld_per_adv.c",0x449);
  }
  r_sch_arb_remove(iVar2,1);
  if (*(char *)(iVar2 + 0x53) != '\x02') {
    *(char *)(iVar2 + 0x16) = *(char *)(iVar2 + 0x16) + rwip_priority;
    iVar2 = *(int *)(&lld_per_adv_env + (uint)*(byte *)(iVar2 + 0x52) * 4);
    *(uint *)(iVar2 + 4) = *(int *)(iVar2 + 4) + *(int *)(iVar2 + 0x40) & 0xfffffff;
    *(short *)(iVar2 + 0x4c) = *(short *)(iVar2 + 0x4c) + 1;
    iVar4 = r_lld_read_clock();
    while ((iVar4 - *(int *)(iVar2 + 4) & 0xfffffffU) < 0x7ffffff) {
      *(uint *)(iVar2 + 4) = *(int *)(iVar2 + 4) + *(int *)(iVar2 + 0x40) & 0xfffffff;
      *(short *)(iVar2 + 0x4c) = *(short *)(iVar2 + 0x4c) + 1;
    }
    cVar3 = '\x0f';
    do {
      iVar4 = r_sch_arb_insert(iVar2);
      if (iVar4 == 0) {
        *(undefined1 *)(iVar2 + 0x53) = 0;
        return;
      }
      cVar3 = cVar3 + -1;
      *(char *)(iVar2 + 0x16) = *(char *)(iVar2 + 0x16) + DAT_0001301b;
      *(uint *)(iVar2 + 4) = *(int *)(iVar2 + 4) + *(int *)(iVar2 + 0x40) & 0xfffffff;
      *(short *)(iVar2 + 0x4c) = *(short *)(iVar2 + 0x4c) + 1;
    } while (cVar3 != '\0');
    r_assert_param("lld_per_adv.c",0x13e);
    return;
  }
  puVar5 = (undefined1 *)r_ke_msg_alloc(0x208,0,0xff,2);
  uVar1 = *(undefined1 *)(iVar2 + 0x52);
  puVar5[1] = 0;
  *puVar5 = uVar1;
  r_ke_msg_send();
  if (*(int *)(&lld_per_adv_env + param_1 * 4) != 0) {
    r_ke_free();
    *(int *)(&lld_per_adv_env + param_1 * 4) = 0;
  }
  return;
}

