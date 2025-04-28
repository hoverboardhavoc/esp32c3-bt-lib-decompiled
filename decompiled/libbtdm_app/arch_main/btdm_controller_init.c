/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> arch_main.o -> btdm_controller_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 btdm_controller_init(int *param_1)

{
  byte bVar1;
  byte bVar2;
  undefined1 uVar3;
  ushort uVar4;
  undefined2 uVar5;
  void *pvVar6;
  int *piVar7;
  int *piVar8;
  char cVar9;
  char *pcVar10;
  int iVar11;
  uint uVar12;
  undefined4 uVar13;
  int iVar14;
  code *pcVar15;
  undefined1 uStack_34;
  byte bStack_33;
  
  uVar13 = 0xffffffff;
  if (_g_rw_init_sem != 0) goto _L335;
  _r_plf_funcs_p =
       (void *)(**(code **)(_r_osi_funcs_p + 0x78))(0x118,*(code **)(_r_osi_funcs_p + 0x78));
  if (((_r_plf_funcs_p == (void *)0x0) ||
      (_r_modules_funcs_p =
            (void *)(**(code **)(_r_osi_funcs_p + 0x78))(0x3d0,*(code **)(_r_osi_funcs_p + 0x78)),
      _r_modules_funcs_p == (void *)0x0)) ||
     (_r_ip_funcs_p =
           (void *)(**(code **)(_r_osi_funcs_p + 0x78))(0x9e4,*(code **)(_r_osi_funcs_p + 0x78)),
     _r_ip_funcs_p == (void *)0x0)) {
    if (0 < _g_bt_plf_log_level) {
      ets_printf("Funcs table create fails\n");
    }
    btdm_funcs_table_destroy();
    uVar13 = 0xfffffffe;
    goto _L335;
  }
  memcpy(_r_plf_funcs_p,&r_plf_funcs_ro,0x118);
  memcpy(_r_modules_funcs_p,&r_modules_funcs_ro,0x3d0);
  memcpy(_r_ip_funcs_p,&r_ip_funcs_ro,0x9e4);
  (**(code **)(_r_osi_funcs_p + 0xe4))(*(code **)(_r_osi_funcs_p + 0xe4));
  if ((*param_1 == 0x5a5aa5a5) && (param_1[1] == 0x2502230)) {
    if (((((uint)param_1[0xb] >> 0x10) - 1 & 0xff) < 2) &&
       ((((uint)param_1[0xb] >> 0x18) - 1 & 0xff) < 2)) {
      if (*(byte *)(param_1 + 0xc) < 2) {
        *(undefined1 *)(param_1 + 0xc) = 2;
      }
      if (*(ushort *)(param_1 + 0xd) < 0x101) {
        if (*(byte *)((int)param_1 + 0x1e) < 0x10) {
          (**(code **)((int)_r_plf_funcs_p + 0x44))(param_1,*(code **)((int)_r_plf_funcs_p + 0x44));
          sdk_config_set_mask(param_1[8]);
          sdk_config_set_opts_ext(param_1 + 8);
          sdk_config_overwrite_priv_opts();
          sdk_config_set_derived_opts();
          iVar11 = (**(code **)((int)_r_plf_funcs_p + 0xf0))(*(code **)((int)_r_plf_funcs_p + 0xf0))
          ;
          if (*(char *)(iVar11 + 0x1e) != '\0') {
            uVar13 = 0xfffffff5;
            if (0 < _g_bt_plf_log_level) {
              ets_printf("Controller lib error, need flash lib\n");
              uVar13 = 0xfffffff5;
            }
            goto _L335;
          }
          if ((*(char *)((int)param_1 + 0x17) == '\0') &&
             (iVar11 = (**(code **)((int)_r_plf_funcs_p + 0xe8))
                                 (param_1[6],*(code **)((int)_r_plf_funcs_p + 0xe8)), iVar11 != 0))
          goto _L449;
          iVar11 = (**(code **)((int)_r_plf_funcs_p + 0x38))(*(code **)((int)_r_plf_funcs_p + 0x38))
          ;
          uStack_34 = *(undefined1 *)(iVar11 + 0xd);
          bStack_33 = DAT_0001302f;
          (**(code **)((int)_r_plf_funcs_p + 0x24))
                    (&uStack_34,*(code **)((int)_r_plf_funcs_p + 0x24));
          if (DAT_0001302e == '\0') {
            btdm_hli_get_null_funcs();
          }
          else {
            btdm_hli_get_funcs();
          }
          btdm_hli_funcs_register();
          _btdm_env_p = (int *)(**(code **)(_r_osi_funcs_p + 0x74))
                                         (0x28,*(code **)(_r_osi_funcs_p + 0x74));
          if (_btdm_env_p != (int *)0x0) {
            memset(_btdm_env_p,0,0x28);
            uVar12 = (**(code **)((int)_r_ip_funcs_p + 0x244))
                               (*(code **)((int)_r_ip_funcs_p + 0x244));
            iVar11 = (**(code **)((int)_r_ip_funcs_p + 0x4d0))
                               (*(code **)((int)_r_ip_funcs_p + 0x4d0));
            if (iVar11 == 0) {
              uVar12 = 0;
            }
            iVar11 = (**(code **)((int)_r_ip_funcs_p + 0xe4))(*(code **)((int)_r_ip_funcs_p + 0xe4))
            ;
            if (iVar11 == 0) {
              uVar12 = 0;
            }
            if ((DAT_0001302d != '\0') &&
               (iVar11 = (**(code **)((int)_r_plf_funcs_p + 0x4c))
                                   (*(code **)((int)_r_plf_funcs_p + 0x4c)), iVar11 == 0)) {
              uVar12 = 0;
            }
            iVar11 = (**(code **)((int)_r_ip_funcs_p + 0x44))(*(code **)((int)_r_ip_funcs_p + 0x44))
            ;
            if ((iVar11 != 0) && ((uVar12 & 1) != 0)) {
              iVar11 = (**(code **)((int)_r_plf_funcs_p + 0x38))
                                 (*(code **)((int)_r_plf_funcs_p + 0x38));
              bVar1 = *(byte *)(iVar11 + 0xd);
              iVar11 = (**(code **)((int)_r_plf_funcs_p + 0x38))
                                 (*(code **)((int)_r_plf_funcs_p + 0x38));
              bVar2 = *(byte *)(iVar11 + 0xd);
              uVar12 = (uint)DAT_0001302f;
              iVar11 = (**(code **)((int)_r_plf_funcs_p + 0x38))
                                 (*(code **)((int)_r_plf_funcs_p + 0x38));
              piVar7 = _btdm_env_p;
              iVar14 = 0;
              if (DAT_0001302e != '\0') {
                iVar14 = uVar12 * 0xe0 + (uint)*(byte *)(iVar11 + 0xd) * 0x88;
              }
              pcVar15 = *(code **)(_r_osi_funcs_p + 0x78);
              _btdm_env_p[1] =
                   ((bVar2 + 2) * 0xc + (uint)bVar1 * 0xe6 + 0x25b + iVar14 & 0xfffffffc) + 0xc;
              iVar11 = (*pcVar15)(pcVar15);
              pvVar6 = _r_plf_funcs_p;
              *piVar7 = iVar11;
              iVar11 = (**(code **)((int)pvVar6 + 0x38))(*(code **)((int)pvVar6 + 0x38));
              piVar7 = _btdm_env_p;
              uVar12 = 0;
              if (DAT_0001302e != '\0') {
                uVar12 = (uint)DAT_0001302f * 400;
                if ((uint)DAT_0001302f * 400 < 0x1800) {
                  uVar12 = 0x1800;
                }
              }
              pcVar15 = *(code **)(_r_osi_funcs_p + 0x78);
              _btdm_env_p[3] =
                   (((uint)*(byte *)(iVar11 + 0xd) * 0x104 + 0x8ef) * 2 + 0x675 + uVar12 &
                   0xfffffffc) + 0xc;
              iVar11 = (*pcVar15)(pcVar15);
              pvVar6 = _r_plf_funcs_p;
              piVar7[2] = iVar11;
              iVar11 = (**(code **)((int)pvVar6 + 0xf0))(*(code **)((int)pvVar6 + 0xf0));
              uVar4 = *(ushort *)(iVar11 + 8);
              iVar11 = (**(code **)((int)_r_plf_funcs_p + 0xf0))
                                 (*(code **)((int)_r_plf_funcs_p + 0xf0));
              piVar7 = _btdm_env_p;
              pcVar15 = *(code **)(_r_osi_funcs_p + 0x78);
              _btdm_env_p[5] =
                   (((uint)*(ushort *)(iVar11 + 6) * 0xc + (uint)uVar4 * 0x10 + 0x293 >> 2) + 3) * 4
              ;
              iVar11 = (*pcVar15)(pcVar15);
              cVar9 = DAT_0001302e;
              piVar7[4] = iVar11;
              piVar7 = _btdm_env_p;
              iVar11 = 1;
              if (cVar9 != '\0') {
                iVar11 = 0xc00;
              }
              pcVar15 = *(code **)(_r_osi_funcs_p + 0x78);
              _btdm_env_p[7] = (iVar11 + 3U & 0xfffffffc) + 0xc;
              iVar11 = (*pcVar15)(pcVar15);
              piVar8 = _btdm_env_p;
              piVar7[6] = iVar11;
              if ((((*piVar8 != 0) && (piVar8[2] != 0)) && (piVar8[4] != 0)) &&
                 ((piVar8[7] == 0 || (piVar8[6] != 0)))) {
                if (2 < _g_bt_plf_log_level) {
                  ets_printf("RWIP Heap alloc: ENV [%p %d], MSG [%p %d], NORET [%p %d], DB [%p %d]\n"
                             ,piVar8[1],piVar8[3],piVar8[5],piVar8[6]);
                }
                iVar11 = (**(code **)((int)_r_plf_funcs_p + 0x38))
                                   (*(code **)((int)_r_plf_funcs_p + 0x38));
                if ((*(char *)(iVar11 + 0x17) != '\0') &&
                   (iVar11 = (**(code **)((int)_r_plf_funcs_p + 0x38))
                                       (*(code **)((int)_r_plf_funcs_p + 0x38)),
                   piVar7 = _btdm_env_p, *(char *)(iVar11 + 0x17) == '\x01')) {
                  iVar11 = (**(code **)(_r_osi_funcs_p + 0x78))
                                     (0xc,*(code **)(_r_osi_funcs_p + 0x78));
                  piVar8 = _btdm_env_p;
                  piVar7[9] = iVar11;
                  if ((void *)piVar8[9] == (void *)0x0) goto _L354;
                  memset((void *)piVar8[9],0,0xc);
                }
                if (2 < _g_bt_plf_log_level) {
                  ets_printf("Uart ENV [%p], VHCI ENV [%p]\n",_btdm_env_p[8],_btdm_env_p[9]);
                }
                _g_rw_init_sem =
                     (**(code **)(_r_osi_funcs_p + 0x24))(1,0,*(code **)(_r_osi_funcs_p + 0x24));
                if (_g_rw_init_sem == 0) {
                  uVar13 = 0xfffffffb;
                }
                else {
                  _g_rw_schd_queue =
                       (**(code **)(_r_osi_funcs_p + 0x4c))(5,8,*(code **)(_r_osi_funcs_p + 0x4c));
                  if (_g_rw_schd_queue == 0) {
                    uVar13 = 0xfffffffa;
                  }
                  else {
                    pcVar15 = *(code **)(_r_osi_funcs_p + 0x24);
                    iVar11 = (**(code **)((int)_r_plf_funcs_p + 0xf8))
                                       (*(code **)((int)_r_plf_funcs_p + 0xf8));
                    uVar13 = (*pcVar15)(1,0);
                    pvVar6 = _r_plf_funcs_p;
                    *(undefined4 *)(iVar11 + 8) = uVar13;
                    iVar11 = (**(code **)((int)pvVar6 + 0xf8))(*(code **)((int)pvVar6 + 0xf8));
                    if (*(int *)(iVar11 + 8) == 0) {
                      uVar13 = 0xfffffff9;
                    }
                    else {
                      _g_waking_sleeping_sem =
                           (**(code **)(_r_osi_funcs_p + 0x24))
                                     (1,1,*(code **)(_r_osi_funcs_p + 0x24));
                      if (_g_waking_sleeping_sem == 0) {
                        return 0xfffffff8;
                      }
                      pcVar15 = *(code **)(_r_osi_funcs_p + 100);
                      iVar11 = (**(code **)((int)_r_plf_funcs_p + 0x38))
                                         (*(code **)((int)_r_plf_funcs_p + 0x38));
                      uVar5 = *(undefined2 *)(iVar11 + 8);
                      iVar11 = (**(code **)((int)_r_plf_funcs_p + 0x38))
                                         (*(code **)((int)_r_plf_funcs_p + 0x38));
                      uVar3 = *(undefined1 *)(iVar11 + 10);
                      iVar11 = (**(code **)((int)_r_plf_funcs_p + 0x38))
                                         (*(code **)((int)_r_plf_funcs_p + 0x38));
                      iVar11 = (*pcVar15)(btdm_controller_task,"btController",uVar5,0,uVar3,
                                          &g_rw_controller_task_handle,*(undefined1 *)(iVar11 + 0xb)
                                         );
                      if (iVar11 == 1) {
                        (**(code **)((int)_r_plf_funcs_p + 0x28))
                                  (7,0,0,1,*(code **)((int)_r_plf_funcs_p + 0x28));
                        (**(code **)(_r_osi_funcs_p + 0x34))
                                  (_g_rw_init_sem,10000,*(code **)(_r_osi_funcs_p + 0x34));
                        return 0;
                      }
                      uVar13 = 0xfffffff7;
                    }
                  }
                }
                goto _L335;
              }
            }
          }
_L354:
          (**(code **)((int)_r_ip_funcs_p + 0x240))(*(code **)((int)_r_ip_funcs_p + 0x240));
          (**(code **)((int)_r_ip_funcs_p + 0x4cc))(*(code **)((int)_r_ip_funcs_p + 0x4cc));
          (**(code **)((int)_r_ip_funcs_p + 0xe0))(*(code **)((int)_r_ip_funcs_p + 0xe0));
          if (DAT_0001302d != '\0') {
            (**(code **)((int)_r_plf_funcs_p + 0x48))(*(code **)((int)_r_plf_funcs_p + 0x48));
          }
          (**(code **)((int)_r_ip_funcs_p + 0x40))(*(code **)((int)_r_ip_funcs_p + 0x40));
          if (*_btdm_env_p != 0) {
            (**(code **)(_r_osi_funcs_p + 0x7c))(*(code **)(_r_osi_funcs_p + 0x7c));
          }
          if (_btdm_env_p[2] != 0) {
            (**(code **)(_r_osi_funcs_p + 0x7c))(*(code **)(_r_osi_funcs_p + 0x7c));
          }
          if (_btdm_env_p[4] != 0) {
            (**(code **)(_r_osi_funcs_p + 0x7c))(*(code **)(_r_osi_funcs_p + 0x7c));
          }
          if (_btdm_env_p[6] != 0) {
            (**(code **)(_r_osi_funcs_p + 0x7c))(*(code **)(_r_osi_funcs_p + 0x7c));
          }
          if (_btdm_env_p[9] != 0) {
            (**(code **)(_r_osi_funcs_p + 0x7c))(*(code **)(_r_osi_funcs_p + 0x7c));
            _btdm_env_p[9] = 0;
          }
          uVar13 = 0xfffffffc;
          if (_btdm_env_p != (int *)0x0) {
            (**(code **)(_r_osi_funcs_p + 0x7c))(*(code **)(_r_osi_funcs_p + 0x7c));
            _btdm_env_p = (int *)0x0;
          }
          goto _L335;
        }
        if (0 < _g_bt_plf_log_level) {
          pcVar10 = "Default Tx Power Invalid: 0x%x\n";
          goto _L450;
        }
      }
      else if (0 < _g_bt_plf_log_level) {
        pcVar10 = "Invalid scan backoff upperlimitmax: 0x%x\n";
        goto _L450;
      }
    }
    else if (0 < _g_bt_plf_log_level) {
      pcVar10 = "Hardware Target Code Invalid: 0x%x\n";
_L450:
      ets_printf(pcVar10);
    }
  }
  else if (0 < _g_bt_plf_log_level) {
    ets_printf("Config struct mismatch: magic=%08x, ver=%08x\n",0x5a5aa5a5,0x2502230);
  }
_L449:
  uVar13 = 0xfffffffd;
_L335:
  btdm_controller_deinit_internal();
  return uVar13;
}

