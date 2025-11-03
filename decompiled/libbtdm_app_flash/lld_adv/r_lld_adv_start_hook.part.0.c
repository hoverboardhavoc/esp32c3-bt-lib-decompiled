/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> lld_adv.o -> r_lld_adv_start_hook.part.0
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_adv_start_hook_part_0(int param_1,int param_2)

{
  ushort uVar1;
  undefined2 uVar2;
  short sVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  
  sVar3 = DAT_000165a8;
  if (((DAT_000165a8 != 0) && (DAT_000165aa != 0)) && (*(int *)(&lld_adv_env + param_1 * 4) != 0)) {
    iVar5 = r_emi_get_mem_addr_by_offset(0x400);
    *(short *)(param_1 * 0x5a + 0xc + iVar5) = sVar3;
    sVar3 = DAT_000165aa;
    iVar5 = r_emi_get_mem_addr_by_offset(0x400);
    *(short *)(param_1 * 0x5a + 0xe + iVar5) = sVar3;
  }
  iVar5 = r_sdk_config_get_opts_ext();
  uVar7 = param_1 * 9 & 0xff;
  if ((*(char *)(iVar5 + 0x18) == '\0') && ((*(ushort *)(param_2 + 0x18) & 0x10) != 0)) {
    iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
    iVar9 = uVar7 * 0xe + 2;
    uVar1 = *(ushort *)(iVar5 + iVar9);
    iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
    *(ushort *)(iVar5 + iVar9) = uVar1 & 0xffdf;
    iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
    iVar5 = (uVar7 + 1 & 0xff) * 0xe + 2;
    uVar1 = *(ushort *)(iVar9 + iVar5);
    iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
    *(ushort *)(iVar9 + iVar5) = uVar1 & 0xffdf;
  }
  iVar5 = *(int *)(&lld_adv_env + param_1 * 4);
  iVar9 = llm_csa_get();
  uVar10 = 2;
  if ((*(ushort *)(iVar5 + 0x74) & 0x10) == 0) {
    uVar10 = (uint)*(byte *)(iVar5 + 0x92);
  }
  if (iVar9 != 0) {
    iVar5 = param_1 * 0x7e + 2;
    for (uVar4 = 0; uVar4 != uVar10; uVar4 = uVar4 + 1 & 0xff) {
      if ((iVar9 - 1U & 0xfe) != 0) {
        r_assert_err(0,0x10000,0x162);
      }
      iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
      uVar1 = *(ushort *)(iVar6 + iVar5);
      iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
      *(ushort *)(iVar6 + iVar5) = (ushort)(((iVar9 - 1U & 0xff) << 0x15) >> 0x10) | uVar1 & 0xffdf;
      iVar5 = iVar5 + 0xe;
    }
  }
  lld_rpa_renew_start(*(undefined1 *)(param_2 + 0x1e));
  for (uVar4 = 0; uVar10 != uVar4; uVar4 = uVar4 + 1 & 0xff) {
    uVar8 = uVar7 + uVar4 & 0xff;
    iVar5 = uVar8 * 0xe;
    iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
    uVar2 = *(undefined2 *)(iVar5 + 2 + iVar9);
    iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
    r_ble_log_internal_x2(0x40c0005a,CONCAT22(*(undefined2 *)(iVar5 + 6 + iVar9),uVar2),uVar8);
  }
  return;
}

