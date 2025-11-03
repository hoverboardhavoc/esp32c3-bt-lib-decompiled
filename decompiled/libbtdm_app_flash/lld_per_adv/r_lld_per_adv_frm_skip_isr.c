/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> lld_per_adv.o -> r_lld_per_adv_frm_skip_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_per_adv_frm_skip_isr(uint param_1)

{
  undefined1 uVar1;
  byte bVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  undefined1 *puVar8;
  
  iVar4 = *(int *)(&lld_per_adv_env + param_1 * 4);
  if (iVar4 == 0) {
    r_assert_err(0,0x10000,0x488);
    return;
  }
  r_ble_log_internal_x1
            (0x404400aa,
             (uint)*(byte *)(iVar4 + 0x53) << 8 | (uint)*(byte *)(iVar4 + 0x16) << 0x10 | param_1);
  if (1 < (byte)(*(char *)(iVar4 + 0x53) - 1U)) {
    r_assert_err(0,0x10000,0x46c);
  }
  r_sch_arb_remove(iVar4,1);
  if (*(char *)(iVar4 + 0x53) == '\x02') {
    puVar8 = (undefined1 *)r_ke_msg_alloc(0x208,0,0xff,2);
    uVar1 = *(undefined1 *)(iVar4 + 0x52);
    puVar8[1] = 0;
    *puVar8 = uVar1;
    r_ke_msg_send();
    piVar3 = (int *)(&lld_per_adv_env + param_1 * 4);
    if (*piVar3 == 0) {
      r_ble_log_internal_x1(0x800400a6,param_1);
      return;
    }
    r_ble_log_internal_x1(0x400400a5,param_1 << 0x10 | (uint)*(ushort *)(*piVar3 + 0x4c));
    r_ke_free(*piVar3);
    *piVar3 = 0;
    return;
  }
  bVar2 = *(byte *)(iVar4 + 0x52);
  *(char *)(iVar4 + 0x16) = *(char *)(iVar4 + 0x16) + rwip_priority;
  iVar4 = *(int *)(&lld_per_adv_env + (uint)bVar2 * 4);
  *(uint *)(iVar4 + 4) = *(int *)(iVar4 + 4) + *(int *)(iVar4 + 0x40) & 0xfffffff;
  *(short *)(iVar4 + 0x4c) = *(short *)(iVar4 + 0x4c) + 1;
  iVar6 = r_lld_read_clock();
  while ((iVar6 - *(int *)(iVar4 + 4) & 0xfffffffU) < 0x7ffffff) {
    *(uint *)(iVar4 + 4) = *(int *)(iVar4 + 4) + *(int *)(iVar4 + 0x40) & 0xfffffff;
    *(short *)(iVar4 + 0x4c) = *(short *)(iVar4 + 0x4c) + 1;
  }
  uVar5 = 0;
  do {
    iVar7 = r_sch_arb_insert(iVar4);
    if (iVar7 == 0) {
      iVar7 = 1;
      goto _L4;
    }
    uVar5 = uVar5 + 1 & 0xff;
    *(char *)(iVar4 + 0x16) = *(char *)(iVar4 + 0x16) + DAT_0001301b;
    *(uint *)(iVar4 + 4) = *(int *)(iVar4 + 4) + *(int *)(iVar4 + 0x40) & 0xfffffff;
    *(short *)(iVar4 + 0x4c) = *(short *)(iVar4 + 0x4c) + 1;
  } while (uVar5 != 0xf);
  iVar7 = 0;
_L4:
  r_ble_log_internal_x1
            (0x404400a2,
             (uint)*(byte *)(iVar4 + 0x53) << 0x18 | (uint)bVar2 | iVar7 << 8 | uVar5 << 0x10);
  if (iVar7 == 0) {
    r_assert_param(*(undefined4 *)(iVar4 + 4),iVar6,0x10000,0x13f);
    return;
  }
  *(undefined1 *)(iVar4 + 0x53) = 0;
  return;
}

