/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
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
  uint uVar12;
  int iVar13;
  int iVar14;
  undefined2 uStack_38;
  undefined2 uStack_36;
  undefined1 uStack_34;
  
  iVar13 = *(int *)(&lld_con_env + param_1 * 4);
  if (iVar13 != 0) {
    bVar1 = *(byte *)(iVar13 + 0x8e);
    iVar8 = r_emi_get_mem_addr_by_offset(0x400);
    iVar14 = (uint)bVar1 * 0x5a;
    iVar8 = r_emi_get_mem_addr_by_offset(0x400,*(undefined2 *)(iVar14 + 0x16 + iVar8));
    uVar2 = *(ushort *)(iVar8 + iVar14 + 4);
    iVar8 = r_emi_get_mem_addr_by_offset(0x400);
    uVar3 = *(ushort *)(iVar8 + iVar14 + 4);
    iVar8 = r_emi_get_mem_addr_by_offset(0x400);
    uVar4 = *(undefined2 *)(iVar8 + iVar14 + 0xe);
    iVar8 = r_emi_get_mem_addr_by_offset(0x400);
    uVar5 = *(undefined2 *)(iVar8 + iVar14 + 0xc);
    iVar8 = r_emi_get_mem_addr_by_offset(0x400);
    uStack_38 = *(undefined2 *)(iVar14 + 0x22 + iVar8);
    iVar8 = r_emi_get_mem_addr_by_offset(0x400);
    uStack_36 = *(undefined2 *)(iVar14 + 0x24 + iVar8);
    iVar8 = r_emi_get_mem_addr_by_offset(0x400);
    uStack_34 = (undefined1)*(undefined2 *)(iVar14 + 0x26 + iVar8);
    uVar9 = r_co_nb_good_le_channels(&uStack_38);
    if ((*(ushort *)(iVar13 + 0x84) & 0x200) == 0) {
      iVar8 = r_emi_get_mem_addr_by_offset(0x400,uVar9);
      uVar6 = *(ushort *)(iVar8 + iVar14 + 0xe);
      iVar8 = r_emi_get_mem_addr_by_offset(0x400);
      uVar7 = *(ushort *)(iVar8 + iVar14 + 0xc);
      iVar8 = r_emi_get_mem_addr_by_offset(0x400);
      uVar10 = r_lld_cca_chan_sel_2
                         (*(undefined2 *)(iVar14 + 0x50 + iVar8),uVar6 ^ uVar7,&uStack_38,uVar9);
    }
    else {
      uVar10 = r_lld_cca_chan_sel_1
                         (*(undefined1 *)(iVar13 + 0x80),*(undefined1 *)(iVar13 + 0x8d),
                          *(undefined2 *)(iVar13 + 0x72),&uStack_38);
    }
    if ((*(ushort *)(iVar13 + 0x84) & 1) == 0) {
      uVar12 = *(uint *)(iVar13 + 4) * 0x271;
      uVar11 = *(int *)(iVar13 + 8) + uVar12;
      uVar11 = ((uint)(uVar11 < uVar12) + (int)((ulonglong)*(uint *)(iVar13 + 4) * 0x271 >> 0x20)) *
               -0x80000000 | uVar11 >> 1;
    }
    else if ((*(ushort *)(iVar13 + 0x84) & 0x100) == 0) {
      uVar12 = *(uint *)(iVar13 + 4) * 0x271;
      uVar11 = *(int *)(iVar13 + 8) + uVar12;
      uVar11 = ((uint)(uVar11 < uVar12) + (int)((ulonglong)*(uint *)(iVar13 + 4) * 0x271 >> 0x20)) *
               -0x80000000 | uVar11 >> 1;
    }
    else {
      uVar12 = *(uint *)(iVar13 + 0x54) * 0x271;
      uVar11 = (int)*(short *)(iVar13 + 0x6e) + uVar12;
      uVar11 = ((uint)(uVar11 < uVar12) +
               (int)((ulonglong)*(uint *)(iVar13 + 0x54) * 0x271 >> 0x20) +
               ((int)*(short *)(iVar13 + 0x6e) >> 0x1f)) * -0x80000000 | uVar11 >> 1;
    }
    r_ble_log_internal_x4
              (0x40430079,CONCAT22(uVar4,uVar5),uVar11,
               (uint)*(ushort *)(iVar13 + 0x7c) | param_3 << 0x18 |
               (uint)*(byte *)(iVar13 + 0x8e) << 0x10,((uVar2 & 0xc) << 2 | uVar3 & 3) << 8 | uVar10
              );
  }
  iVar13 = r_lld_con_terminate_max_evt_update
                     (param_1,(int)(uint)*(ushort *)(*(int *)(&lld_con_env + param_1 * 4) + 0x84) >>
                              8 & 1);
  if (iVar13 != 0) {
    return;
  }
  iVar13 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar13 + 0x19) == '\x02') {
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

