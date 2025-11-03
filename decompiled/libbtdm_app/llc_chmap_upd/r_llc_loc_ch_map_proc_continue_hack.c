/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app -> llc_chmap_upd.o -> r_llc_loc_ch_map_proc_continue_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llc_loc_ch_map_proc_continue_hack(int param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  code *UNRECOVERED_JUMPTABLE;
  short sVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  void *pvVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  byte abStack_28 [12];
  
  iVar2 = *(int *)(&llc_env + param_1 * 4);
  iVar4 = (**(code **)(_r_ip_funcs_p + 0x674))(0,*(code **)(_r_ip_funcs_p + 0x674));
  iVar5 = (**(code **)(_r_ip_funcs_p + 0x680))(*(code **)(_r_ip_funcs_p + 0x680));
  if (iVar5 == param_2) {
    iVar5 = (**(code **)(_r_ip_funcs_p + 0x680))(iVar4,*(code **)(_r_ip_funcs_p + 0x680));
    if (iVar5 == 0) {
      pvVar7 = (void *)(**(code **)(_r_ip_funcs_p + 0x4ec))(*(code **)(_r_ip_funcs_p + 0x4ec));
      memcpy(abStack_28,pvVar7,5);
      uVar8 = (**(code **)(_r_modules_funcs_p + 0xc))
                        (abStack_28,*(code **)(_r_modules_funcs_p + 0xc));
      bVar1 = *(byte *)(iVar2 + 0x1f);
      if (uVar8 < bVar1) {
        uVar10 = 0;
        do {
          if (((int)(uint)abStack_28[(int)uVar10 >> 3] >> (uVar10 & 7) & 1U) == 0) {
            abStack_28[(int)uVar10 >> 3] = abStack_28[(int)uVar10 >> 3] | (byte)(1 << (uVar10 & 7));
            uVar8 = uVar8 + 1 & 0xff;
            if (bVar1 <= uVar8) break;
          }
          uVar10 = uVar10 + 1;
        } while (uVar10 != 0x25);
      }
      iVar9 = memcmp((void *)(iVar2 + 8),abStack_28,5);
      iVar5 = _r_ip_funcs_p;
      if (iVar9 != 0) {
        *(ushort *)(iVar2 + 0x42) = *(ushort *)(iVar2 + 0x42) | 0x10;
        pvVar7 = (void *)(iVar4 + 8);
        sVar3 = (**(code **)(iVar5 + 0x338))(param_1,*(code **)(iVar5 + 0x338));
        sVar3 = sVar3 + *(short *)(iVar2 + 0x10) + 9;
        *(short *)(iVar4 + 0xe) = sVar3;
        memcpy(pvVar7,abStack_28,5);
        iVar5 = (**(code **)(_r_ip_funcs_p + 0x31c))
                          (param_1,pvVar7,sVar3,*(code **)(_r_ip_funcs_p + 0x31c));
        if (iVar5 == 0) {
          llc_llcp_ch_map_update_ind_pdu_send(param_1,*(undefined2 *)(iVar4 + 0xe),pvVar7);
          (**(code **)(_r_ip_funcs_p + 0x684))(iVar4,param_1,1,*(code **)(_r_ip_funcs_p + 0x684));
          return;
        }
      }
    }
    else {
      if (iVar5 != 1) {
        UNRECOVERED_JUMPTABLE = *(code **)(_r_plf_funcs_p + 0xc);
        uVar6 = (**(code **)(_r_ip_funcs_p + 0x680))(iVar4,*(code **)(_r_ip_funcs_p + 0x680));
                    /* WARNING: Could not recover jumptable at 0x000101ee. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*UNRECOVERED_JUMPTABLE)(param_1,uVar6,0x10000,0xcf,UNRECOVERED_JUMPTABLE);
        return;
      }
      memcpy((void *)(iVar2 + 8),(void *)(iVar4 + 8),5);
    }
  }
  *(ushort *)(iVar2 + 0x42) = *(ushort *)(iVar2 + 0x42) & 0xffef;
  (**(code **)(_r_ip_funcs_p + 0x690))(param_1,0,*(code **)(_r_ip_funcs_p + 0x690));
  *(ushort *)(iVar2 + 0x42) = *(ushort *)(iVar2 + 0x42) & 0xfeff;
  return;
}

