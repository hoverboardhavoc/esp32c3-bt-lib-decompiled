/*
 * Last changed at upstream commit eeb2782618e0ab8cf0cf609c98c6a0c86d691a6c
 * https://github.com/espressif/esp32c3-bt-lib/commit/eeb2782618e0ab8cf0cf609c98c6a0c86d691a6c
 * Upstream date: 2024-10-20 16:32:16 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(52ee788)
 * Source: libbtdm_app -> llc_chmap_upd.o -> r_llc_loc_ch_map_proc_continue
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llc_loc_ch_map_proc_continue(int param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  code *pcVar3;
  short sVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  void *pvVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  byte abStack_28 [12];
  
  iVar2 = *(int *)(&llc_env + param_1 * 4);
  iVar5 = (**(code **)(_r_ip_funcs_p + 0x674))(0,*(code **)(_r_ip_funcs_p + 0x674));
  iVar6 = (**(code **)(_r_ip_funcs_p + 0x680))(*(code **)(_r_ip_funcs_p + 0x680));
  if (iVar6 == param_2) {
    iVar6 = (**(code **)(_r_ip_funcs_p + 0x680))(iVar5,*(code **)(_r_ip_funcs_p + 0x680));
    if (iVar6 == 0) {
      pvVar8 = (void *)(**(code **)(_r_ip_funcs_p + 0x4ec))(*(code **)(_r_ip_funcs_p + 0x4ec));
      memcpy(abStack_28,pvVar8,5);
      uVar9 = (**(code **)(_r_modules_funcs_p + 0xc))
                        (abStack_28,*(code **)(_r_modules_funcs_p + 0xc));
      bVar1 = *(byte *)(iVar2 + 0x1f);
      if (uVar9 < bVar1) {
        uVar11 = 0;
        do {
          if (((int)(uint)abStack_28[(int)uVar11 >> 3] >> (uVar11 & 7) & 1U) == 0) {
            abStack_28[(int)uVar11 >> 3] = (byte)(1 << (uVar11 & 7)) | abStack_28[(int)uVar11 >> 3];
            uVar9 = uVar9 + 1 & 0xff;
            if (bVar1 <= uVar9) break;
          }
          uVar11 = uVar11 + 1;
        } while (uVar11 != 0x25);
      }
      iVar10 = memcmp((void *)(iVar2 + 8),abStack_28,5);
      iVar6 = _r_ip_funcs_p;
      if (iVar10 != 0) {
        *(ushort *)(iVar2 + 0x42) = *(ushort *)(iVar2 + 0x42) | 0x10;
        pvVar8 = (void *)(iVar5 + 8);
        sVar4 = (**(code **)(iVar6 + 0x338))(param_1,*(code **)(iVar6 + 0x338));
        sVar4 = *(short *)(iVar2 + 0x10) + 9 + sVar4;
        *(short *)(iVar5 + 0xe) = sVar4;
        memcpy(pvVar8,abStack_28,5);
        iVar6 = (**(code **)(_r_ip_funcs_p + 0x31c))
                          (param_1,pvVar8,sVar4,*(code **)(_r_ip_funcs_p + 0x31c));
        if (iVar6 == 0) {
          llc_llcp_ch_map_update_ind_pdu_send(param_1,*(undefined2 *)(iVar5 + 0xe),pvVar8);
          (**(code **)(_r_ip_funcs_p + 0x684))(iVar5,param_1,1,*(code **)(_r_ip_funcs_p + 0x684));
          return;
        }
      }
    }
    else {
      if (iVar6 != 1) {
        pcVar3 = *(code **)(_r_plf_funcs_p + 0xc);
        uVar7 = (**(code **)(_r_ip_funcs_p + 0x680))(iVar5,*(code **)(_r_ip_funcs_p + 0x680));
        (*pcVar3)(param_1,uVar7,"llc_chmap_upd.c",0xcc);
        return;
      }
      memcpy((void *)(iVar2 + 8),(void *)(iVar5 + 8),5);
    }
  }
  *(ushort *)(iVar2 + 0x42) = *(ushort *)(iVar2 + 0x42) & 0xffef;
  (**(code **)(_r_ip_funcs_p + 0x690))(param_1,0,*(code **)(_r_ip_funcs_p + 0x690));
  *(ushort *)(iVar2 + 0x42) = *(ushort *)(iVar2 + 0x42) & 0xfeff;
  return;
}

