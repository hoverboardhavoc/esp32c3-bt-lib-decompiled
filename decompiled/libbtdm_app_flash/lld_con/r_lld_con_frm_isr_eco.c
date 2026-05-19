/*
 * Last changed at upstream commit 7e73ebf92e5aa995065351043c13d2ac0f00772e
 * https://github.com/espressif/esp32c3-bt-lib/commit/7e73ebf92e5aa995065351043c13d2ac0f00772e
 * Upstream date: 2026-05-19 17:43:45 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(bc853c5)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_frm_isr_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_con_frm_isr_eco(int param_1,undefined4 param_2,int param_3)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  ushort uVar6;
  ushort uVar7;
  int iVar8;
  undefined4 uVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  undefined2 uStack_38;
  undefined2 uStack_36;
  undefined1 uStack_34;
  
  iVar12 = *(int *)(&lld_con_env + param_1 * 4);
  if (iVar12 == 0) goto _L623;
  bVar1 = *(byte *)(iVar12 + 0x8e);
  iVar8 = r_emi_get_mem_addr_by_offset(0x400);
  iVar13 = (uint)bVar1 * 0x5a;
  iVar8 = r_emi_get_mem_addr_by_offset(0x400,*(undefined2 *)(iVar13 + 0x16 + iVar8));
  uVar2 = *(ushort *)(iVar8 + iVar13 + 4);
  iVar8 = r_emi_get_mem_addr_by_offset(0x400);
  uVar3 = *(ushort *)(iVar8 + iVar13 + 4);
  iVar8 = r_emi_get_mem_addr_by_offset(0x400);
  uVar4 = *(undefined2 *)(iVar8 + iVar13 + 0xe);
  iVar8 = r_emi_get_mem_addr_by_offset(0x400);
  uVar5 = *(undefined2 *)(iVar8 + iVar13 + 0xc);
  iVar8 = r_emi_get_mem_addr_by_offset(0x400);
  uStack_38 = *(undefined2 *)(iVar13 + 0x22 + iVar8);
  iVar8 = r_emi_get_mem_addr_by_offset(0x400);
  uStack_36 = *(undefined2 *)(iVar13 + 0x24 + iVar8);
  iVar8 = r_emi_get_mem_addr_by_offset(0x400);
  uStack_34 = (undefined1)*(undefined2 *)(iVar13 + 0x26 + iVar8);
  uVar9 = r_co_nb_good_le_channels(&uStack_38);
  if ((*(ushort *)(iVar12 + 0x84) & 0x200) == 0) {
    iVar8 = r_emi_get_mem_addr_by_offset(0x400,uVar9);
    uVar6 = *(ushort *)(iVar8 + iVar13 + 0xe);
    iVar8 = r_emi_get_mem_addr_by_offset(0x400);
    uVar7 = *(ushort *)(iVar8 + iVar13 + 0xc);
    iVar8 = r_emi_get_mem_addr_by_offset(0x400);
    iVar8 = r_lld_cca_chan_sel_2
                      (*(undefined2 *)(iVar13 + 0x50 + iVar8),uVar6 ^ uVar7,&uStack_38,uVar9);
  }
  else {
    iVar8 = r_lld_cca_chan_sel_1
                      (*(undefined1 *)(iVar12 + 0x80),*(undefined1 *)(iVar12 + 0x8d),
                       *(undefined2 *)(iVar12 + 0x72),&uStack_38);
  }
  if ((*(ushort *)(iVar12 + 0x84) & 1) == 0) {
    uVar11 = *(uint *)(iVar12 + 4) * 0x271;
    uVar10 = *(int *)(iVar12 + 8) + uVar11;
    iVar13 = (uint)(uVar10 < uVar11) + (int)((ulonglong)*(uint *)(iVar12 + 4) * 0x271 >> 0x20);
_L635:
    uVar10 = iVar13 << 0x1f | uVar10 >> 1;
  }
  else {
    if ((*(ushort *)(iVar12 + 0x84) & 0x100) != 0) {
      uVar11 = *(uint *)(iVar12 + 0x54) * 0x271;
      uVar10 = (int)*(short *)(iVar12 + 0x6e) + uVar11;
      iVar13 = (uint)(uVar10 < uVar11) +
               (int)((ulonglong)*(uint *)(iVar12 + 0x54) * 0x271 >> 0x20) +
               ((int)*(short *)(iVar12 + 0x6e) >> 0x1f);
      goto _L635;
    }
    uVar11 = *(uint *)(iVar12 + 4) * 0x271;
    uVar10 = *(int *)(iVar12 + 8) + uVar11;
    uVar10 = ((uint)(uVar10 < uVar11) + (int)((ulonglong)*(uint *)(iVar12 + 4) * 0x271 >> 0x20)) *
             -0x80000000 | uVar10 >> 1;
  }
  r_ble_log_internal_x4
            (0x40430001,CONCAT22(uVar4,uVar5),uVar10,*(undefined2 *)(iVar12 + 0x7c),
             iVar8 << 0x10 |
             ((uVar2 & 0xc) << 2 | uVar3 & 3) << 0x18 |
             (uint)*(byte *)(iVar12 + 0x8e) | param_3 << 8);
_L623:
  iVar12 = r_emi_get_mem_addr_by_offset(0x400);
  r_ble_log_internal_x1(0x404300fc,param_1 << 0x10 | *(ushort *)(param_1 * 0x5a + iVar12) & 0x1f);
  iVar12 = r_lld_con_terminate_max_evt_update
                     (param_1,(int)(uint)*(ushort *)(*(int *)(&lld_con_env + param_1 * 4) + 0x84) >>
                              8 & 1);
  if (iVar12 != 0) {
    return;
  }
  iVar12 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar12 + 0x19) == '\x02') {
    r_lld_cca_con_evt_end_handle();
  }
  r_lld_con_frm_isr(param_1,param_2,param_3);
  if (con_evt_func_cb == (code *)0x0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00010014. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*con_evt_func_cb)(param_1,0);
  return;
}

